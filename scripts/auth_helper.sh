#!/bin/bash

# *********************************************************************************************************************************
# *                                                                                                                   ;           *
# *                                                                                                                  ED.          *
# *                        ,;                             ,;                                                  :      E#Wi         *
# *                      f#i          .    .            f#i j.         t                                      Ef     E###G.       *
# *             ..     .E#t  GEEEEEEELDi   Dt         .E#t  EW,        Ej             ..           ..       : E#t    E#fD#W;      *
# *            ;W,    i#W,   ,;;L#K;;.E#i  E#i       i#W,   E##j       E#,           ;W,          ,W,     .Et E#t    E#t t##L     *
# *           j##,   L#D.       t#E   E#t  E#t      L#D.    E###D.     E#t          j##,         t##,    ,W#t E#t    E#t  .E#K,   *
# *          G###, :K#Wfff;     t#E   E#t  E#t    :K#Wfff;  E#jG#W;    E#t         G###,        L###,   j###t E#t fi E#t    j##f  *
# *        :E####, i##WLLLLt    t#E   E########f. i##WLLLLt E#t t##f   E#t       :E####,      .E#j##,  G#fE#t E#t L#jE#t    :E#K: *
# *       ;W#DG##,  .E#L        t#E   E#j..K#j...  .E#L     E#t  :K#E: E#t      ;W#DG##,     ;WW; ##,:K#i E#t E#t L#LE#t   t##L   *
# *      j###DW##,    f#E:      t#E   E#t  E#t       f#E:   E#KDDDD###iE#t     j###DW##,    j#E.  ##f#W,  E#t E#tf#E:E#t .D#W;    *
# *     G##i,,G##,     ,WW;     t#E   E#t  E#t        ,WW;  E#f,t#Wi,,,E#t    G##i,,G##,  .D#L    ###K:   E#t E###f  E#tiW#G.     *
# *   :K#K:   L##,      .D#;    t#E   f#t  f#t         .D#; E#t  ;#W:  E#t  :K#K:   L##, :K#t     ##D.    E#t E#K,   E#K##i       *
# *  ;##D.    L##,        tt     fE    ii   ii           tt DWi   ,KK: E#t ;##D.    L##, ...      #G      ..  EL     E##D.        *
# *  ,,,      .,,                 :                                    ,;. ,,,      .,,           j           :      E#t          *
# *                                                                                                                  L:           *
# *********************************************************************************************************************************
# *                                                                                                                               *
# *                                                  AetheriaMUD code                                                             *
# *                               copyright (c) 2025 /dev/null Industries - StygianRenegade                                       *
# *                                                                                                                               *
# *********************************************************************************************************************************
# *                                           Character Authorization Helper Script                                               *
# *                  This script helps authorize new characters when the spec_auth special function isn't working                 *
# *********************************************************************************************************************************

# Get the script directory and set up paths
SCRIPT_DIR="$(dirname "$0")"
BASE_DIR="$(cd "$SCRIPT_DIR/.." && pwd)"

echo "SWR MUD Character Authorization Helper"
echo "====================================="
echo ""

echo "This script helps with character authorization when the automatic"
echo "system isn't working due to spec_auth special function issues."
echo ""

echo "To authorize a character manually:"
echo ""
echo "1. Start the server and create your immortal character"
echo "2. Have the new player create their character (they'll be stuck unauthorized)"
echo "3. Login as an immortal and use: authorize <playername> yes"
echo ""

echo "Example immortal commands:"
echo "  authorize Rokkwarr yes     - Authorize player named Rokkwarr"
echo "  authorize                  - List all pending authorizations"
echo ""

echo "The authorize command will:"
echo "  ✅ Remove PCFLAG_UNAUTHED flag"
echo "  ✅ Set auth_state to 3 (fully authorized)"
echo "  ✅ Record who authorized them"
echo "  ✅ Allow them to play normally"
echo ""

echo "Alternative: Fix the spec_auth function by rebuilding the server"
echo "  cd $BASE_DIR/src"
echo "  make clean"
echo "  make"
echo ""

echo "The authorization system should work automatically when:"
echo "  - Players go through the training hall (rooms 227-248)"
echo "  - They reach the Academy Steward (mob #248)"
echo "  - The spec_auth special function processes them"
echo "  - They get a school diploma and full authorization"
echo ""

read -p "Press Enter to continue..."
