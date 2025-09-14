#!/usr/bin/env python3
# *****************************************************************************************
# *                      .___________. __    __   _______                                 *
# *                      |           ||  |  |  | |   ____|                                *
# *                      `---|  |----`|  |__|  | |  |__                                   *
# *                          |  |     |   __   | |   __|                                  *
# *                          |  |     |  |  |  | |  |____                                 *
# *                          |__|     |__|  |__| |_______|                                *
# *                                                                                       *
# *                _______  __  .__   __.      ___       __                               *
# *               |   ____||  | |  \ |  |     /   \     |  |                              *
# *               |  |__   |  | |   \|  |    /  ^  \    |  |                              *
# *               |   __|  |  | |  . `  |   /  /_\  \   |  |                              *
# *               |  |     |  | |  |\   |  /  _____  \  |  `----.                         *
# *               |__|     |__| |__| \__| /__/     \__\ |_______|                         *
# *                                                                                       *
# *      _______ .______    __       _______.  ______    _______   _______                *
# *     |   ____||   _  \  |  |     /       | /  __  \  |       \ |   ____|               *
# *     |  |__   |  |_)  | |  |    |   (----`|  |  |  | |  .--.  ||  |__                  *
# *     |   __|  |   ___/  |  |     \   \    |  |  |  | |  |  |  ||   __|                 *
# *     |  |____ |  |      |  | .----)   |   |  `--'  | |  '--'  ||  |____                *
# *     |_______|| _|      |__| |_______/     \______/  |_______/ |_______|               *
# *****************************************************************************************
# *                                                                                       *
# * Star Wars: The Final Episode additions and changes from the Star Wars Reality code    *
# * copyright (c) 2025 /dev/null Industries - StygianRenegade                             *
# *****************************************************************************************
# *                     Fallback server for when shit crashes                             *
# *****************************************************************************************
"""
Fallback Telnet Server for SWR MUD
THE FINAL EPISODE

Simple maintenance server when main MUD is down
"""

import socket
import threading
import time
import sys
import signal
import random

# Humorous fortunes shown to connecting users
maintenance_fortunes = [
    "This downtime brought to you by 'Have You Tried Turning It Off & On Again?'",
    "A broken server is just an unexpected coffee break—enjoy.",
    "The force is not with us. Perhaps try a Jedi mind trick on your router?",
    "Behind every great outage is an IT person screaming internally.",
    "May your connection be stronger than your urge to curse the sysadmin.",
    "In a galaxy far, far away... the server works perfectly.",
    "When 900 years old you reach, crash as often you will not.",
    "These are not the bytes you're looking for.",
    "Help me Obi-Wan Kenobi, our server is our only hope."
]

class FallbackServer:
    def __init__(self, port=4848, max_connections=10):
        self.port = port
        self.max_connections = max_connections
        self.running = True
        self.connections = []

        # Multi-line message template. Use .format() to substitute values.
        self.message = """
\033[1;36m═══════════════════════════════════════════════════════════════════════════════\033[0m
\033[1;33m                    Star Wars Reality MUD - Server Status                       \033[0m
\033[1;36m═══════════════════════════════════════════════════════════════════════════════\033[0m

\033[1;31mSERVER TEMPORARILY UNAVAILABLE\033[0m

The main game server is currently down for maintenance or experiencing
technical difficulties. Our administrators have been notified and are
working to restore service.

\033[1;32mWhat you can do:\033[0m
- Check back in a few minutes
- Visit our website for updates
- Contact us for urgent issues: support@renegadeinc.net

\033[1;33mServer Status:\033[0m Maintenance Mode (Fallback Active)
\033[1;33mPort:\033[0m {port}
\033[1;33mLast Update:\033[0m {timestamp}
\033[1;33mFallback Server:\033[0m Online since {server_start}

\033[0;90mConnection will close in 30 seconds...\033[0m

\033[0;33m❝ {fortune} ❞\033[0m

"""

        # Store server start time
        self.server_start_time = time.strftime('%Y-%m-%d %H:%M:%S')

    def handle_client(self, client_socket, client_address):
        """Handle individual client connection"""
        try:
            timestamp = time.strftime('%Y-%m-%d %H:%M:%S')
            print(f"\033[32m[{timestamp}] Client connected from: {client_address[0]}:{client_address[1]}\033[0m")

            # Select a random fortune from our list
            fortune = random.choice(maintenance_fortunes)

            # Offer basic Telnet GMCP negotiation so modern MU* clients can detect us
            # Telnet control bytes
            IAC = b'\xff'   # 255
            DONT = b'\xfe'  # 254
            DO = b'\xfd'    # 253
            WONT = b'\xfc'  # 252
            WILL = b'\xfb'  # 251
            SB = b'\xfa'    # 250
            SE = b'\xf0'    # 240
            GMCP = bytes([201])

            try:
                # Announce support and request the option so clients that support GMCP can respond
                # Send: IAC WILL GMCP and IAC DO GMCP (best-effort)
                client_socket.send(IAC + WILL + GMCP)
                client_socket.send(IAC + DO + GMCP)

                # Send a simple GMCP Core.Hello payload
                hello_payload = 'Core.Hello {"client":"swr-fallback","version":"1.0"}'
                try:
                    client_socket.send(IAC + SB + GMCP + hello_payload.encode('ascii') + IAC + SE)
                except Exception:
                    # If ascii fails for any reason, fallback to utf-8 safe encoding
                    client_socket.send(IAC + SB + GMCP + hello_payload.encode('utf-8', errors='replace') + IAC + SE)
            except Exception:
                # Ignore negotiation errors; non-GMCP clients will simply ignore these bytes
                pass

            # Compose and send welcome message
            message = self.message.format(
                timestamp=timestamp,
                port=self.port,
                server_start=self.server_start_time,
                fortune=fortune
            )

            # Ensure bytes are sent in a safe encoding; fall back to latin-1 if needed
            try:
                client_socket.send(message.encode('utf-8'))
            except UnicodeEncodeError:
                client_socket.send(message.encode('latin-1', errors='replace'))

            # Keep the connection open briefly so user can read message
            time.sleep(30)

            # Send closing message and close
            try:
                client_socket.send(b"\nConnection closed.\n")
            except Exception:
                pass

        except Exception as e:
            print(f"\033[31mError handling client {client_address}: {e}\033[0m")
        finally:
            try:
                client_socket.close()
                timestamp = time.strftime('%Y-%m-%d %H:%M:%S')
                print(f"\033[33m[{timestamp}] Client disconnected: {client_address[0]}:{client_address[1]}\033[0m")
            except Exception:
                pass

            # Remove from connections list
            try:
                self.connections.remove(client_socket)
            except ValueError:
                pass

    def start(self):
        """Start the fallback server"""
        # Check if port appears in use; this is advisory only
        self._check_port_availability()

        server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        server_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)

        try:
            server_socket.bind(('', self.port))
            server_socket.listen(self.max_connections)

            print("\033[36m═══════════════════════════════════════════════════════════════════════════════\033[0m")
            print("\033[33m                        SWR MUD FALLBACK SERVER\033[0m")
            print("\033[36m═══════════════════════════════════════════════════════════════════════════════\033[0m")
            print()
            print(f"\033[33mPort:\033[0m \033[32m{self.port}\033[0m")
            print(f"\033[33mMax Connections:\033[0m \033[32m{self.max_connections}\033[0m")
            print(f"\033[33mStatus:\033[0m \033[31mMain server is DOWN - Fallback active\033[0m")
            print(f"\033[33mStarted:\033[0m \033[36m{time.strftime('%Y-%m-%d %H:%M:%S')}\033[0m")
            print()
            print("\033[34mListening for connections... (Ctrl+C to stop)\033[0m")
            print()

            while self.running:
                try:
                    client_socket, client_address = server_socket.accept()

                    # Check connection limit
                    if len(self.connections) >= self.max_connections:
                        try:
                            client_socket.send(b"Server is busy. Please try again later.\n")
                        except Exception:
                            pass
                        client_socket.close()
                        continue

                    self.connections.append(client_socket)

                    # Handle client in separate thread
                    client_thread = threading.Thread(
                        target=self.handle_client,
                        args=(client_socket, client_address)
                    )
                    client_thread.daemon = True
                    client_thread.start()

                except socket.error as e:
                    if self.running:
                        print(f"\033[31mSocket error: {e}\033[0m")
                        break
                except KeyboardInterrupt:
                    break

        except OSError as e:
            if getattr(e, 'errno', None) == 98:  # Address already in use
                print(f"\033[31mError: Port {self.port} is already in use.\033[0m")
                print("This usually means:")
                print("- Another MUD server is running on this port")
                print("- A previous fallback server is still running")
                print("- The main server is actually running")
                print()
                print("Please check:")
                print(f"  ps aux | grep {self.port}")
                print(f"  ss -tlnp | grep :{self.port}")
                print()
                return 1
            else:
                print(f"\033[31mError: Cannot bind to port {self.port}: {e}\033[0m")
                return 1
        finally:
            try:
                self.stop()
            except Exception:
                pass
            try:
                server_socket.close()
            except Exception:
                pass

        return 0

    def _check_port_availability(self):
        """Check if the target port is available"""
        import subprocess

        try:
            # Check what's using the port (best-effort, not fatal)
            result = subprocess.run(
                ['ss', '-tlnp', f'sport = :{self.port}'],
                capture_output=True,
                text=True,
                timeout=3
            )

            if result.stdout.strip():
                print(f"\033[33mWarning: Port {self.port} appears to be in use:\033[0m")
                for line in result.stdout.strip().split('\n')[1:]:  # Skip header
                    print(f"  {line}")
                print()
                print("\033[33mFallback server will attempt to bind anyway (SO_REUSEADDR enabled)\033[0m")
                print()
        except (subprocess.TimeoutExpired, subprocess.CalledProcessError, FileNotFoundError):
            # If ss command fails, just continue
            pass

    def stop(self):
        """Stop the server"""
        print()
        print("\033[33mShutting down fallback server...\033[0m")
        self.running = False

        # Close all client connections
        for client_socket in list(self.connections):
            try:
                client_socket.close()
            except Exception:
                pass

        self.connections.clear()
        print("\033[32mFallback server stopped.\033[0m")


def signal_handler(signum, frame):
    """Handle shutdown signals"""
    print("\nReceived shutdown signal...")
    sys.exit(0)


if __name__ == "__main__":
    # Set up signal handlers
    signal.signal(signal.SIGINT, signal_handler)
    signal.signal(signal.SIGTERM, signal_handler)

    # Parse command line arguments
    port = 4848
    if len(sys.argv) > 1:
        if sys.argv[1] in ['--help', '-h', 'help']:
            print("SWR MUD Fallback Server")
            print("Usage: fallback_server.py [port]")
            print("  port    Port number to listen on (default: 4848)")
            print("")
            print("This server provides a maintenance message when the main MUD is down.")
            sys.exit(0)
        try:
            port = int(sys.argv[1])
        except ValueError:
            print("Error: Port must be a number")
            print("Usage: fallback_server.py [port]")
            sys.exit(1)

    # Start server
    server = FallbackServer(port)
    sys.exit(server.start())
