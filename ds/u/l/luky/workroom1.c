// Room: /u/l/luky/workroom.c
#include <ansi.h>  //­Y­n¥Î¦³ÃC¦âªº¶·¥[¦¹¦æ
#include <room.h> //­n¥[ªù­n³o¤@¦æ
#include <path.h>
inherit ROOM;
inherit DOOR;
void entercheck(object ob);
void create()
{
 set("short",HIG"®ü©³¥­­ì"NOR);  //µu±Ô­z
 set("long","\n"
 HIB"¢o"NOR"                      ³o¸Ì¬O®ü©³®l¨¦ªº³Ì²`³B¡E¡E¡E¡E¡E¡E¡E¡E¡E¡E\n"
 HIB"¢p"HIW"  o"NOR"¢X             ´X±ø«D±`¨u¨£ªº²`®ü³½±q§A¨­Ãä´å¹L¡A¤@°¦"HIY"ª÷¶À¦â"NOR"ªº\n"
 HIB"¢p"NOR"      ¢X          "HIY"¤pÀs½¼"NOR"¬ðµM¦b§A¨­ÃäÅS¥X¤F¨eªºÀY¡AÁÙ¦R¥X¤@ÁûÁûªº\n"
 BLU"¢o"NOR"  ¢X    "HIG"£i £p"NOR"     ¤p®ðªw¡A§Aª`·N¨ì¨e®ÇÃäªº©¥¾À¤WÁÙ¨è¤F´X­Ó¤j¦r¡C\n"
 BLU"¢n"HIY"¢¡"NOR"¢X"HIB"  ¢¨¢i¢h¢i¢i¢©"HIW"¢X"NOR+GRN"£i      "NOR"¢X"HIG"    £p"NOR"\n"
 BLU"¢o"HIY"¢H¢¡"HIB"¢¨¢i"HIC"½Ð¤ÅÁý­¹"HIB"¢i"BLU"¢h¢g"HIB"¢f¢e¢e¢f¢e¢e¢f¢e¢e¢f¢e¢d¢c¢b"NOR"\n"
 BLU"¢i"HIB"¢i¢h¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢h¢g¢f¢e"BLU"¢d¢c¢b"NOR"\n"
 ); //ªø±Ô­z

 set("light",1);
 set("exits", ([  //¦¹©Ð¶¡³sµ²¤§¥X¤f¤è¦V¤ÎÀÉ®×
 "east": __DIR__"lukyroom1",
 "west": __DIR__"lukylab1",
 "fonsan": LUKY+"fonsan/eega1",
 "wiz": "/d/wiz/hall1",
 ]));
 set("hide_exits", ([
 "ship":__DIR__"workroom",
 ]));
 set("no_clean_up", 0);
 set("light",1);
 set("objects",([
  __DIR__"npc/passenger":1,
  __DIR__"npc/pig":1,
  __DIR__"box":1,
  __DIR__"redkey":1,
 ]));
 create_door("east","¬õ¦â¤jªù","west",DOOR_LOCKED,"redkey");
// set("never_clean",1); //¤@¯ë©Ð¶¡µ´¤£¥i¥[¦¹¦æ.
 setup();
// call_other( "/obj/board/luky_b", "???" );
}

void init()
{
 call_out("leave_message",3,this_player());
 call_out("entercheck",2,this_player());
}

void entercheck(object ob)
{
 if(userp(ob))
 {
   if(wiz_level(ob) < wiz_level("(immortal)"))
   {
     message_vision(HIR"¹ï¤£°_ "+ob->name()+" §A¤£¯à¶i¨Ó³á!!\n"NOR, ob);
     ob->move("/d/slake/start");
   } else 
   {
     message_vision(HIY"\n ¤pÀs½¼»¡: ¶Ù!! "+ob->name()+"¤j¤j! §Ú¦n·Q§A³á!!\n"NOR, ob);
   }
 }
 return;
}

void leave_message(object me)  //*****³X«È°Ê§@*****
{
 object luky,ob1,ob2;
 if(luky=find_player("luky")) //¥»¤H¦b¹CÀ¸¤¤
 {
  if(me->query("id")!="luky") //§O¤H¶i¤J
  {
   ob1=find_object(__DIR__"workroom");
   ob2=present("luky",ob1);
   if(ob2) return; //¥»¤H¦b©Ð¶¡¤º§Y¨ú®ø°Ê§@
   add("guest",me->query("id")+" - "); //¬ö¿ý³X«È
   tell_object(luky,"[1;37m¦³³X«È¨ÓÅo!("+me->query("name")+")[m\n");
   tell_object(me,"[1;37mÀs½¼(Luky)§i¶D§A: ¶Ù!Åwªï¥úÁ{!!§Ú°¨¤W¦^¨Ó©Û©I§A![m\n");
  } else //of if(me->query("id")!="luky") ¥»¤H¶i¤J
  {
   if(query("guest")) //¦³³X«È¬ö¿ý
   {
    tell_object(me,"[1;37m¤µ¤Ñªº³X«È¦³:"+query("guest")+"[m\n");
    delete("guest");
   } else //of if(query("guest")) ¨S¦³³X«È¬ö¿ý
   {
          //tell_object(me,"[1;37m¤µ¤ÑÁÙ¨S¦³³X«È¨Ó¹L[m\n");
   }
  }
 } else //of if(luky=find_player("luky")) ¥»¤H¤£¦b¹CÀ¸¤¤
 {
  add("guest",me->query("id")+" - ");  //¬ö¿ý³X«È
  tell_object(me,"[1;37m¤pÀs½¼(Lobster)§i¶D§A: LukyÁÙ¨S¨Ó³á..[m\n");
 }
 
 if( file_size("/u/l/luky/note")>0 )
 {
  write(WHT"=======================Às½¼³Æ§Ñ¿ý=========================\n");
  me->start_more( read_file("/u/l/luky/note") ); //me->cat("/u/l/luky/note");
  write("\n"NOR);
 }
 
}

