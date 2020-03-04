#include <ansi.h>
#include <net/dns.h>
#include <net/telnet.h>
#include <net/socket.h>
#include <net/socket_errors.h>
#include <socket_err.h>
#include <mudlib.h>
inherit ITEM;

// Static var
static int m_socket;
static int socket_no1;
static int socket_no2;
static object me;
static int status=0; // Create Socket status..

object telnet = this_object();

int write_message(string); // this Functoin Write Scoket Message.

// Listen Socket Message For This User

void listen(string arg){tell_object(environment(telnet),arg);} 
// Create This object .

void create()
{
set_name(HIW"³s½u¹CÀ¸¾÷"NOR, ({ "computer" }) );

         set("long", @LONG
telnet 203.71.167.75 5000

³s½u¤¤...............

               ¢c¢c¢c¢c¢c¢c¢c¢c¢c¢c¢c¢c¢c¢c¢c¢c¢c¢c¢c¢c¢c¢c
                               - ­·¤§ª«»y -
               ŸmŸmŸmŸmŸmŸmŸmŸmŸmŸmŸmŸmŸmŸmŸmŸmŸmŸmŸmŸmŸmŸm

                   | -                                - |
                           ¥» Mud ¬O©ÓÅ§ Es2lib
                   | -                                - |

                        * ¥»¯¸³]¸m©ó 1999 ¦~ 6 ¤ë *
                          BBS :  203.72.48.43 tww_mudª©
                          WizMud : 203.71.167.75 9000


                oO¢ÝOo   ·Qª±¶Ü¡H¶i¨Ó´Nª¾¹D¦h¦nª±   oO¢ÝOo



­·¤§ª«»y¤w¸g¦b­·¤¤ÄÆ¿º¤F¤@¤Ñ¤@¤p®É¤­¤Q¤G¤À¤G¤Q¤K¬í

¥Ø«e¦@¦³ 2 ¦ì§Å®v¡B6 ¦ìª±®a¦b½u¤W¡M¥H¤Î 2 ¦ì¨Ï¥ÎªÌ¹Á¸Õ³s½u¤¤¡C

±zªº­^¤å¦W¦r¡R
LONG
        );

        set_max_encumbrance(0);
                if( clonep() )
                        set_default_object(__FILE__);
                else {  set("unit", "¥x");      }

                setup();
}
// Add_action For User
void init()
{
                add_action("close_socket","close");
                add_action("write_message","z");
                add_action("do_telnet","telnet");
}

// Telnet Login

int do_telnet(string arg)
{
        int err;
        if( query("connected") )
                        socket_close(m_socket);

        m_socket = socket_create(STREAM, "in_read_callback","in_close_callback");

        if ( m_socket < 0 ){
                listen("µLªkªì©l¤Æ Socket .\n" );
                return 1;
        }

       err = socket_connect(m_socket,arg,"read_callback","write_callback" );

        if( err==EESUCCESS ) {
                listen("¥¿³s½u¦Ü - " + arg + "\n");
                set("connected",1);
        }else

        listen("µLªk³s½u¦Ü - " + arg + "\n");
        return 1;
}

// Close This Socket

int close_socket()
{
        if( query("connected") ){
                        if( socket_close(m_socket) ) {
                                listen("Ãö³¬ telnet socket!!\n");
                                delete("connected");
                        }else
                                listen("Ãö³¬ telnet socket ¥X¿ù.\n");
                }
        else
                listen("¥Ø«e¨Ã¨S¦³³s½u¡C\n");
        return 1;
}

// socket listen Telnet Message_

void read_callback(int fd, mixed message)
{
        listen(HIY"¡÷"NOR + (message));return ;
}

void write_callback(int fd)
{
        int sta;

        if(query("connect"))
                return ;
        sta = socket_write( fd,"");

                if (sta == EESUCCESS || sta == EECALLBACK)
                                set("connected",1);

}
// Write Socket Message.

int write_message(string arg)
{
        if( !arg ) arg="";

                socket_write(m_socket,arg+"\n"); // \n = enter keys _

        return 1;
} 

