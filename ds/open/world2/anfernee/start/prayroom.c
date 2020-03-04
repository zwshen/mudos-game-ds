#include <path.h>

inherit ROOM;
//string look_sign(object me);
void greeting(object me);
void create()
{
        set("short", "®ÉªÅ¯«·µ");
        set("long", @LONG
³o¸Ì¬O®ÈÀ]ªþ³]ªº¯«·µ¡C³\¦h°@¸Ûªº«H©^ªÌ³£³ßÅw¦b³o¸ÌÀR«ä­×¨­¡A
³o¸ÌªºÆF®ð«Ü±j¡A©Ò¥H±`±`§l¤Þ³\¦h©t»î³¥°­»E¶°¦b¦¹±µ¨ü¯«½çªº®¦¨å¡C
³o¸Ì¦³¨â®y¯«¹³¡A¤À§O¬O´xºÞ¥Í©R¤§¯«[Shengsan]©M´xºÞ¦º¤`¤§¯«[Luky]
ªºÀJ¹³(statues)¡C

                      ¢®  
                        ¢­  
                     _£[_.O.           k
                    /\__.\/ ¢­      O  |
                    \/__\         ()Y==o
                     | :|          /_\ |   
                     | :|          _W_ |   
                   ¢g¢i¢i¢g      ¢g¢i¢i¢g
                   ¢i¢i¢i¢i      ¢i¢i¢i¢i

 ¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã¡Ã
LONG
        );

        set("exits", ([ /* sizeof() == 1 */
  "down" :"/open/world1/tmr/area/hotel",        ]) );
        set("item_desc", ([
                "statues": "  ¨â®y¯Â»É¥´³yªºÀJ¹³(statue of luky)(statue of shengsan), §A¬Ý\n"+
                           "¨ì¦³¨Ç¥b³z©úÆFÅé¥¿³òÂ¶µÛ¨ä¤¤¤@­ÓÀJ¹³½¤«ô(pray)µÛ¡C\n\n",
        ]) );
        set("hide_item_desc", ([
                "statue of luky": @STATUE_L
  ¤@´L¤Q¤ÀÄYµÂªºÀJ¹³¡A¤@¤â«ù¬Þ¤@¤â«ù¥Ù¡A´N¹³¬O¶Ç»¡¤¤¥D®_¦º¬ÉªºÅ]¯«
  ªº§Î»ª¡C
STATUE_L,
                "statue of shengsan": @STATUE_S
  §A«Ü¦n©_¬°¤°»ò³o¨â­Ó¯«¹³·|©ñ¦b¤@°_¡A©M®ÇÃäÄYµÂªºÀJ¹³¤ñ°_¨Ó¡A³o´L
ÀJ¹³¦ü¥G·O²»³\¦h¡Aµ¹¤H¤@ºØ¦w¥þµÎªAªº·PÄ±¡C
STATUE_S,
                "luky": @STATUE_L2
  ¤@´L¤Q¤ÀÄYµÂªºÀJ¹³¡A¤@¤â«ù¬Þ¤@¤â«ù¥Ù¡A´N¹³¬O¶Ç»¡¤¤¥D®_¦º¬ÉªºÅ]¯«
ªº§Î»ª¡C

STATUE_L2,
                "shengsan": @STATUE_S2
  §A«Ü¦n©_¬°¤°»ò³o¨â­Ó¯«¹³·|©ñ¦b¤@°_¡A©M®ÇÃäÄYµÂªºÀJ¹³¤ñ°_¨Ó¡A³o´L
ÀJ¹³¦ü¥G·O²»³\¦h¡Aµ¹¤H¤@ºØ¦w¥þµÎªAªº·PÄ±¡C
STATUE_S2,
                
        ]) );
        set("light",1);
        set("no_fight",1);
        set("no_kill",1);
        setup();
}

void init()
{
 add_action("do_pray","pray");
 if(this_player()->is_ghost()) call_out("greeting",20,this_player());
}

void greeting(object me)
{
        if( !me ) return;
        if(environment(me)==this_object() && me->is_ghost())
                write("¹[0;1m[[1m´[1m£[1m¥[1mÜ[1m][1m [1m§[1mA[1m¤[1mw[1m¸[1mg[1m¥[1m¢[1m¥[1mh[1m¤[1mF[1mÂ[1mß[1mÅ[1mé[1m¡[1mA[1m¤[1mU[1m [1mp[1mr[1ma[1my[1m [1ml[1mu[1mk[1my[1m [1m«[1mü[1m¥[1mO[1m¥[1mi[1m¥[1mH[1mÅ[1mý[1m§[1mA[1m´[1m_[1m¬[1m¡[1m¡[1mC[1m¹[0m\n");
        return;
}

int do_pray(string arg)
{
        object me;
        me=this_player();
 
 if(!arg) return notify_fail("§A·Q¹ï­þ¤@­ÓÀJ¹³¬èÃ«©O?\n");
 if(arg=="luky")
 {
        if(me->is_ghost())
        {
         me->reincarnate();
        me->delete_temp("kill_love");
         message_vision("¹[0;1m$[1mN[1m°[1m@[1m¸[1mÛ[1mª[1mº[1m¦[1mV[1m¦[1mº[1m¤[1m`[1m¤[1m§[1m¯[1m«[1m¬[1mè[1mÃ[1m«[1m¡[1mA[1m¬[1mð[1mµ[1mM[1m¤[1m@[1m°[1m}[1m¥[1mú[1m¨[1m~[1m·[1mÓ[1m®[1mg[1m¦[1mb[1m$[1mN[1m¨[1m­[1m¤[1mW[1m¡[1mA[1m$[1mN[1m´[1m_[1m¬[1m¡[1m¤[1mF[1m¡[1mC[1m¹[0m\n", me);
         return 1;
        } else return notify_fail("§A°@¸Ûªº¹³ÀJ¹³¬èÃ«¡AÄ±±o¤ß±¡¥­ÀR¤F³\\¦h¡C\n");
 }
 
 if(arg=="shengsan")
 {
        if(me->is_ghost()) return notify_fail("¹[0;1m¤[1mÑ[1m¤[1mW[1m¶[1mÇ[1m¨[1mÓ[1m¦[1mB[1m§[1mN[1mª[1mº[1mÁ[1mn[1m­[1mµ[1m:[1m [0m[0;1m¹[1;33m§[1mÚ[1m¥[1mu[1m¯[1mà[1mÀ[1m°[1m§[1mU[1m¦[1m³[1m¥[1mÍ[1m©[1mR[1mª[1mº[1m¤[1mH[1m¡[1mA[1m§[1mA[1mÁ[1mÙ[1m¬[1mO[1m§[1mä[1m¨[1mä[1m¥[1mL[1m¯[1m«[1mÀ[1m°[1m§[1mA[1m§[1ma[1m¡[1mC[1m¹[0m\n");
        if((me->query("hp")<me->query("max_hp") || me->query("wound")) && me->query("level")<6 )
        {
         me->reincarnate();
         message_vision("¹[0;1;32m$[1mN[1m°[1m@[1m¸[1mÛ[1mª[1mº[1m¦[1mV[1m¥[1mÍ[1m©[1mR[1m¤[1m§[1m¯[1m«[1m¬[1mè[1mÃ[1m«[1m¡[1mA[1m¬[1mð[1mµ[1mM[1m¤[1m@[1m°[1m}[1m¥[1mú[1m¨[1m~[1m·[1mÓ[1m®[1mg[1m¦[1mb[1m$[1mN[1m¨[1m­[1m¤[1mW[1m¡[1mC[1m¹[0m\n", me);
         tell_object(me,"§Aªº¨­Åéª¬ªp§¹¥þ¦^´_¤F¡C\n");
         return 1;
        } else return notify_fail("§A°@¸Ûªº¹³ÀJ¹³¬èÃ«¡AÄ±±o¤ß±¡¥­ÀR¤F³\\¦h¡C\n");
 }
 if(arg=="statues" || arg=="statue") return notify_fail("§A·Q¹ï­þ¤@­ÓÀJ¹³¬èÃ«©O(shengsan),(luky)?\n");
 return 0;
}

int valid_leave(object me, string dir)
{
        if( dir=="down" && me->is_ghost() )
                return notify_fail("§AÁÙ¬O°­»î¡C(pray luky¥i¥H´_¬¡)\n");
        return ::valid_leave(me, dir);
}

