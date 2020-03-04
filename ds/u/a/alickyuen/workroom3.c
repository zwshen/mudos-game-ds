#include <ansi.h>
inherit ROOM;
// string look_list(object me);
int do_say(string arg);
void create()
{
	set("short", MAG"天下第一地獄工作室"NOR);
set("long",
BLK"你正在袁世凱的一號工作室裡，門前放著兩隻ＮＰＣ，一隻叫酒井法
子，另一隻是他的保鑣。另外你還看見地上有一個信箱和一個小標記，上
邊好像寫了一些字。\n"NOR
);
	set("item_desc", ([ /* sizeof() == 1 */
  "小標記" : "努力寫CLASS中！\n",
"信箱" : "一個信箱，你可以找找裡頭有沒有信。\n",
// "rich_list": (: look_list :),
]));
	set("world", "future");
	set("light", 1);
	set("valid_startroom", 1);
	set("exits", ([ /* sizeof() == 8 */
  "enter" : __DIR__"workroom2.c",
  "east" : "/d/wiz/hall1",
"mj" : "/open/world1/tmr/area/mjroom", 
"area" : __DIR__"down_city/map_11_8",
  "ticket" : "/open/world2/shengsan/aovandis/room001",
"guild":"/d/wiz/hall_guild",
"future":"/open/world3/alickyuen/area/inn.c",
]));
  set("objects",([
//  __DIR__"npc/1":1,
 __DIR__"npc/sguard2":1,
 ]));
        set("no_kill",1);
        set("no_exert",1);
        set("no_fight",1);
        set("no_cast",1);
        set("no_recall",1);
 //       set("no_goto",1);
    set("no_shoot",1);
// set("no_home",1);
	set("no_clean_up", 0);
	setup();
 call_other("/obj/board/alickyuen_b", "???");
	}
void init()
{
        call_out("leave_message",3,this_player());
        call_out("entercheck",2,this_player());
add_action("do_say","say");
add_action("do_kickgo","kickgo");
add_action("do_search","search");
}

void entercheck(object ob)
{
 if(userp(ob))
 {
  if(wiz_level(ob) < wiz_level("(immortal)"))  
  {
   message_vision(HIR"酒井法子說："+ob->name()+" 你跑來這裡，你又想說可口可樂大人呀！﹖\n"NOR, ob);
   ob-> move ("/d/wiz/hall1");
  } else {
   message_vision(HIY"\n可口可樂-保鑣說道:  "+ob->name()+",這麼早來悼念可口可樂大人呀....-_-\n"NOR, ob);
  }
 }
 return;
}

void leave_message(object me)
{
        object alickyuen,ob2;
        if( alickyuen=find_player("alickyuen"))
        {
                if(me->query("id")!="alickyuen")
                {
                        ob2=present("alickyuen",this_object());
                        if( ob2 ) return;
                        add("guest",me->query("id")+" - ");
                        tell_object(alickyuen ,"有訪客來囉!("+me->query("name")+")\n");
                        tell_object(me,"酒井法子告訴你:可口可樂復活了！﹖\n");
                }
                else
                {
                        if(query("guest"))
  {
                                tell_object(me,"今天的訪客有:"+query("guest")+"\n");
                                delete("guest");
                        }
                        else
                        {
                                tell_object(me,"今天還沒有訪客來過\n");
                        }
                }
        }
        else
        {
                add("guest",me->query("id")+" - ");
                tell_object(me,"可口可樂-保鑣說道: 可口可樂大人死了，為他悼念吧！\n");
        }
 

}
int do_say(string arg)
{
	if(!arg) return 0;
	remove_call_out("rush");
	arg = replace_string(arg, "$BLK$", BLK);
	arg = replace_string(arg, "$RED$", RED);
	arg = replace_string(arg, "$GRN$", GRN);
	arg = replace_string(arg, "$YEL$", YEL);
	arg = replace_string(arg, "$BLU$", BLU);
	arg = replace_string(arg, "$MAG$", MAG);
	arg = replace_string(arg, "$CYN$", CYN);
	arg = replace_string(arg, "$WHT$", WHT);
	arg = replace_string(arg, "$HIR$", HIR);
	arg = replace_string(arg, "$HIG$", HIG);
	arg = replace_string(arg, "$HIY$", HIY);
	arg = replace_string(arg, "$HIB$", HIB);
	arg = replace_string(arg, "$HIM$", HIM);
	arg = replace_string(arg, "$HIC$", HIC);
	arg = replace_string(arg, "$HIW$", HIW);
	arg = replace_string(arg, "$NOR$", NOR);
	arg = replace_string(arg, "$BEEP$", BEEP);
	message_vision(HIY+"$N說:"+arg+"\n"NOR,this_player());
	//write( YEL"你說﹕" + arg + "\n"NOR );
//	message("sound", YEL + name + "說﹕" +  arg + "\n"NOR ,
//		environment(me), me); 
         call_out("rush",300);
        return 1;
}
int do_kickgo(string arg)
{
	object me,who;
	string chief;
	me=this_player();
	//if(!stringp(chief=this_object()->find_living("alickyuen")) ) return notify_fail("目前並沒有開會!\n");
	//if( me->query("id")!=chief ) return notify_fail("目前只有袁世凱("+chief+")才能踢人!\n");
	if(!arg) return notify_fail("你要踢誰出去!?\n");
	who = present(arg, this_object());
	if(!who) return notify_fail("這裡沒有這個人。\n");
	if( who == me ) return notify_fail("你不能將自己踢出工作室。\n");
	message_vision(HIW"$N將$n踢出工作室。\n"NOR,me,who);
	add("kickgo",({ who->query("id") }));
	who->move("/d/wiz/hall1");
	return 1;
}
/*
string look_list(object me)
{
        return RECORD_D->query_future_money_rec();
}
*/

int do_search(string arg)
{
        object me,to;
        me = this_player();
        to = new("/open/always/newspaper.c");
        if( !arg ) return 0;
        if( arg!="信箱" ) return 0;
if( query_temp("getpap") )
{
    return 0;
}
        message_vision("$N從信箱中拿出一份夢幻日報。\n",me);
        to->move(me);
        set_temp("getpap",1);
        call_out("delay",180,this_object());
        return 1;
}

void delay(object room)
{
      delete_temp("getpap");
        return;
}
