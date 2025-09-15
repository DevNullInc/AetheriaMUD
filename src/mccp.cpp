/*********************************************************************************************************************************
 *                                                                                                                   ;           *
 *                                                                                                                  ED.          *
 *                        ,;                             ,;                                                  :      E#Wi         *
 *                      f#i          .    .            f#i j.         t                                      Ef     E###G.       *
 *             ..     .E#t  GEEEEEEELDi   Dt         .E#t  EW,        Ej             ..           ..       : E#t    E#fD#W;      *
 *            ;W,    i#W,   ,;;L#K;;.E#i  E#i       i#W,   E##j       E#,           ;W,          ,W,     .Et E#t    E#t t##L     *
 *           j##,   L#D.       t#E   E#t  E#t      L#D.    E###D.     E#t          j##,         t##,    ,W#t E#t    E#t  .E#K,   *
 *          G###, :K#Wfff;     t#E   E#t  E#t    :K#Wfff;  E#jG#W;    E#t         G###,        L###,   j###t E#t fi E#t    j##f  *
 *        :E####, i##WLLLLt    t#E   E########f. i##WLLLLt E#t t##f   E#t       :E####,      .E#j##,  G#fE#t E#t L#jE#t    :E#K: *
 *       ;W#DG##,  .E#L        t#E   E#j..K#j...  .E#L     E#t  :K#E: E#t      ;W#DG##,     ;WW; ##,:K#i E#t E#t L#LE#t   t##L   *
 *      j###DW##,    f#E:      t#E   E#t  E#t       f#E:   E#KDDDD###iE#t     j###DW##,    j#E.  ##f#W,  E#t E#tf#E:E#t .D#W;    *
 *     G##i,,G##,     ,WW;     t#E   E#t  E#t        ,WW;  E#f,t#Wi,,,E#t    G##i,,G##,  .D#L    ###K:   E#t E###f  E#tiW#G.     *
 *   :K#K:   L##,      .D#;    t#E   f#t  f#t         .D#; E#t  ;#W:  E#t  :K#K:   L##, :K#t     ##D.    E#t E#K,   E#K##i       *
 *  ;##D.    L##,        tt     fE    ii   ii           tt DWi   ,KK: E#t ;##D.    L##, ...      #G      ..  EL     E##D.        *
 *  ,,,      .,,                 :                                    ,;. ,,,      .,,           j           :      E#t          *
 *                                                                                                                  L:           *
 *********************************************************************************************************************************
 *                                                                                                                               *
 *                AetheriaMUD additions and changes from the Star Wars Reality code                                              *
 *                copyright (c) 2025 /dev/null Industries - StygianRenegade                                                     *
 *                                                                                                                               *
 *                Star Wars Reality Code Additions and changes from the Smaug Code copyright (c) 1997                            *
 *                by Sean Cooper                                                                                                 *
 *                                                                                                                               *
 *           Starwars and Starwars Names copyright(c) Disney Enterprises, Inc.... All hail the mouse overlord!                   *
 *                                                                                                                               *
 *********************************************************************************************************************************
 *                                                                                                                               *
 *                                             SWR 1.0 copyright (c) 1997, 1998 was created by Sean Cooper                       *
 *                                                                                                                               *
 *                           Based on a concept and ideas from the original SWR immortals:                                       *
 *                Himself (Durga), Mark Matt (Merth), Jp Coldarone (Exar), Greg Baily (Thrawn),                                  *
 *                Ackbar, Satin, Streen and Bib as well as much input from our other builders and players.                       *
 *                                                                                                                               *
 *                           Original SMAUG 1.4a written by Thoric (Derek Snider) with:                                          *
 *                Altrag, Blodkai, Haus, Narn, Scryn, Swordbearer, Tricops, Gorog, Rennard,                                      *
 *                Grishnakh, Fireblade, and Nivek.                                                                               *
 *                                                                                                                               *
 *                           Original MERC 2.1 code by: Hatchet, Furey, and Kahn.                                                *
 *                                                                                                                               *
 *                           Original DikuMUD code by: Hans Staerfeldt, Katja Nyboe, Tom Madsen,                                 *
 *                Michael Seifert, and Sebastian Hammer.                                                                         *
 *                                                                                                                               *
 *********************************************************************************************************************************/

/*
 * mccp.c - support functions for mccp (the Mud Client Compression Protocol)
 *
 * see https://smaugmuds.afkmods.com/mccp/
 *
 * Copyright (c) 1999, Oliver Jowett <oliver@randomly.org>.
 *
 * This code may be freely distributed and used if this copyright notice is
 * retained intact.
 */

#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <arpa/telnet.h>
#include "mud.hpp"
#include "mccp.hpp"

#if defined(__OpenBSD__) || defined(__FreeBSD__)
#define ENOSR 63
#endif

const unsigned char will_compress2_str[] = { IAC, WILL, TELOPT_COMPRESS2, '\0' };
const unsigned char start_compress2_str[] = { IAC, SB, TELOPT_COMPRESS2, IAC, SE, '\0' };

bool process_compressed( DESCRIPTOR_DATA * d )
{
   int iStart = 0, nBlock, nWrite, len;

   if( !d->mccp->out_compress )
      return TRUE;

   /*
    * Try to write out some data.. 
    */
   len = d->mccp->out_compress->next_out - d->mccp->out_compress_buf;

   if( len > 0 )
   {
      /*
       * we have some data to write 
       */
      for( iStart = 0; iStart < len; iStart += nWrite )
      {
         nBlock = UMIN( len - iStart, 4096 );
         if( ( nWrite = write( d->descriptor, d->mccp->out_compress_buf + iStart, nBlock ) ) < 0 )
         {
            if( errno == EAGAIN || errno == ENOSR )
               break;

            return FALSE;
         }

         if( !nWrite )
            break;
      }

      if( iStart )
      {
         /*
          * We wrote "iStart" bytes 
          */
         if( iStart < len )
            memmove( d->mccp->out_compress_buf, d->mccp->out_compress_buf + iStart, len - iStart );

         d->mccp->out_compress->next_out = d->mccp->out_compress_buf + len - iStart;
      }
   }
   return TRUE;
}

bool compressStart( DESCRIPTOR_DATA * d )
{
   z_stream *s;

   if( d->mccp->out_compress )
      return TRUE;

   CREATE( s, z_stream, 1 );
   CREATE( d->mccp->out_compress_buf, unsigned char, COMPRESS_BUF_SIZE );

   s->next_in = NULL;
   s->avail_in = 0;

   s->next_out = d->mccp->out_compress_buf;
   s->avail_out = COMPRESS_BUF_SIZE;

   s->zalloc = Z_NULL;
   s->zfree = Z_NULL;
   s->opaque = NULL;

   if( deflateInit( s, 9 ) != Z_OK )
   {
      DISPOSE( d->mccp->out_compress_buf );
      DISPOSE( s );
      return FALSE;
   }

   write_to_descriptor( d, (const char *)start_compress2_str, 0 );

   d->can_compress = TRUE;
   d->mccp->out_compress = s;

   return TRUE;
}

bool compressEnd( DESCRIPTOR_DATA * d )
{
   unsigned char dummy[1];

   if( !d->mccp->out_compress )
      return TRUE;

   d->mccp->out_compress->avail_in = 0;
   d->mccp->out_compress->next_in = dummy;

   if( deflate( d->mccp->out_compress, Z_FINISH ) == Z_STREAM_END )
      process_compressed( d );   /* try to send any residual data */

   deflateEnd( d->mccp->out_compress );
   DISPOSE( d->mccp->out_compress_buf );
   DISPOSE( d->mccp->out_compress );

   return TRUE;
}

void do_compress( CHAR_DATA * ch, const char *argument )
{
   if( !ch->desc )
   {
      send_to_char( "What descriptor?!\n", ch );
      return;
   }

   if( !ch->desc->mccp->out_compress )
   {
      if( !compressStart( ch->desc ) )
         send_to_char( "&RCompression failed to start.\n\r", ch );
      else
         send_to_char( "&GOk, compression enabled.\n", ch );
   }
   else
   {
      compressEnd( ch->desc );
      ch->desc->can_compress = FALSE;
      send_to_char( "&ROk, compression disabled.\n", ch );
   }
}