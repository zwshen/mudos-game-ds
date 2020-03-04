#include <ansi.h>
#define UP_DOOR "climb"
#define DOWN_DOOR "out"
inherit ROOM;
int index=1;
int close_time;
int indexp=0;
int stay=1;
//³]©w¥Øªº¦a¶¶§Ç
string *place=({
"/d/wiz/hall1",
"/u/s/shengsan/workroom",
"/u/l/luky/workroom1",
});
//¬Û¹ï©óplace¶¶§Çªº¯è¦æ®É¶¡
int *span_time=({25,30,40});
//¯è¦æ®Éªº°T®§(¨C5¬í¤@¦¸)
string *float_msg=({
"²M²Dªº®ü­··L·L¦a§j©Ø§AªºÁyÀU¡C\n",
"¤@°}¤j®ö¥´¨Ó¡A§â§Aªº¿ÇºÞµ¹¥´Àã¤F¡C\n",
"¬ðµM¦³¤@°¦®üÅÃ±q§AªºÀY¤W­¸¹L¡C\n",
"²î¨­½w½wªº·n¤F¤@¤U¡C\n",
"¬ðµM¦³°¦®ü³b±q§A¸}®Ç±´¥XÀY¨Ó¡A¹L¤F¤@·|¨à¤S¼ç¤F¤U¥h¡C\n",
});
void start();
void boat(string);
void swim(int);
string query_filename()
{
  return place[index];
}

int getall()
{
  int i;
  for(i=0;i<sizeof(place);i++)
    if(stay)
      tell_object(this_player(),sprintf("%2d %10s %s %s \n",
           i+1,
           i==indexp ? HIY"¥Ø«e°±¦b->"NOR:"  ",
           place[i]->query("short"),
wiz_level(this_player())>=wiz_level("(apprentice)")?"=> ("+place[i]+")":"
      ));
     else
      tell_object(this_player(),sprintf("%2d %8s %s %s \n",
           i+1,
           i==index ? HIY"¤U¤@¯¸->"NOR:" ",
           place[i]->query("short"),
 wiz_level(this_player())>=wiz_level("(apprentice)")?"=> ("+place[i]+")":"
"
             ));

  return 1;
}

void create()
{
//seteuid(getuid());
set("short","¤j¿ÀÃÉ");
set("name","¤j¿ÀÃÉ¹");
set("id","cancership");
set("long", @LONG
              ¢¨¢i¢i¢i¢©                  ¢¨¢i¢i¢i¢©
            ¢¨¢i¢i¢«  ¢ª¢©              ¢¨¢i¢«  ¢ª¢i¢©
        ¢¨¢i¢i¢i¢«                                 ¢ª¢i¢©
     ¢¨¢i¢i¢i¢i¢©¢b¢b¢¨¢i¢«             ¢©      ¢¨¢i¢i¢i¢©
      ¢i¢i¢«  ¢ª¢i¢i¢i¢i¢«               ¢ª¢i¢i¢i¢i¢«  ¢ª¢i¢©
      ¢ª¢i¢©                ¡ó          ¡ó               ¢i¢«
        ¢ª¢i¢i¢©            ùø          ùø           ¢¨¢i¢«
             ¢ª¢i¢i¢© ¢b¢d¢e¢g¢g¢h¢i¢h¢g¢g¢e¢d¢b¢¨¢i¢i¢«
            ¢b¢d¢f¢h¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢h¢f¢d¢b
    ¢¨¢i¢i¢©¢ª¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢«¢¨¢i¢i¢©
  ¢¨¢«    ¢ª¢©¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢¨¢«    ¢ª¢©
¢¨¢«          ¢ª¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢«          ¢ª¢©
        ¢¨¢i¢i¢«¢i¢i¢i¢i¢h¢g¢f¢e¢d¢c¢d¢e¢f¢g¢h¢i¢i¢i¢i¢ª¢i¢©
      ¢¨¢«      ¢ª¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢«    ¢ª¢©
    ¢¨¢«    ¢¨¢i¢©¢ª¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢«¢¨¢i¢©    ¢ª¢©
    ¢«    ¢¨¢«    ¢¨¢«¢ª¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢i¢«¢ª¢©  ¢ª¢©    ¢ª
          ¢i      ¢i        ¢ª¢i¢i¢i¢i¢i¢«        ¢i    ¢i
          ¢ª      ¢ª¢©                          ¢¨¢«    ¢« 
LONG);
set("unit","°¦");
set("light",1);
set("no_kill",1);
set("ship_long",@LONG
§A¥¿¯¸¦b¤j¿ÀÃÉ­I¤Wªº¤p¤ì¥x¤W¡A¤ì¥x¬O¥Ñ¼Æ¤Q¤äª÷­è¤ì¾ð·F»Î±µ¦Ó¦¨¡C
¤W­±¦³´X­ÓÂ²³æªº¤ì´È¥H¤Î¤@±i¤è«¬ªº®à¤l¡A¨c©Tªº°v¦b¤ìªO¤W¡C®à¤l¤W¦³¤@
±i¦a¹Ï(Map) ©M¤@±i¯È(Note)¡C¥Ñ©ó¤j¿ÀÃÉ©_¯Sªº¨µ´å²ß©Ê¡A¨Ï±o¤H­Ì¥i¥H¤è
«Kªº¶V¬v®È¦æ¡A¬Æ¦Ü¤£¥²¥I¥N»ù¡C

LONG
);
set("item_desc",([
  "note":"\n®È«È½Ðª`·N¥H¤U¦u«h: \n\n"
        +"   1. ½Ð¤Å¶Ã¥á©U§£, ¦@¦Pºû«ùÀô¹Ò¾ã¼ä.\n"
        +"   2. ¥i¥H¥Î(List)¨Ó¬Ý¬Ýªu³~¦³°±¾aªº¦aÂI.\n\n",
  "map":"\n§Aµo²{¨º¥u¬O¤@±i¥Õ¯È, ¦ü¥GÁÙ¨Sµe¦n¡C\n",
]));
setup();
call_other( "/obj/board/luky_b", "???" );
call_out("boat",0,place[index]->query("short"));
}
void init()
{
        object ob;
        ob=this_player();
        start();
        add_action("getall","list");

}
void start()
{
    object me;
    me=this_player();
    message_vision(HIG"$Nµn¤W¤F"+this_object()->query("name")+" ¡C\n"NOR,me);
}

void swim(int secs)
{
        int k;
        k=random(7)+6;
        if(secs>7)
        {
                tell_room(this_object(),float_msg[random(sizeof(float_msg))]);
                secs-=k;
                remove_call_out("swim");
                call_out("swim",k,secs);
        }
        else
        {
                tell_room(this_object(),"\n§Ú­Ì§Y±N©è¹F¥Øªº¦a: "+place[index]->query("short")+"\n");
                remove_call_out("swim");
                call_out("boat",7,"«e¥¿©¹ "+place[index]->query("short")+"¤¤");
        }
}

void boat(string ss)
{
  object ob,this_ship,temp_ship,ob1,ob2;
  string s;
  mapping ex;
  this_ship=this_object();
  set("exits",([
  DOWN_DOOR: place[index],
  ]));
  s=sprintf(" %s\n"NOR, (place[index])->query("short"));
  set("long",this_object()->query("ship_long")+HIR"  ¤j¿ÀÃÉ"HIG"¥¿°±¾a¦b"+s+"\n "NOR);
  tell_room(this_object(),HIG"\n  §Ú­Ì¤w¸g©è¹F "+place[index]->query("short")+" !!\n\n"NOR);
  tell_room(this_object(),HIW"  ­nÂ÷¶}ªº®È«È½Ð±Æ¶¤Â÷¶}(out)..\n"+NOR+"\n");
  setup();
  ex=place[index]->query("exits");
// add by Nilekil
        ob1=new("/u/l/luky/tempship.c");
        ob2=find_object(place[index]);
        ob1->move(ob2);
  tell_room(place[index],
HIC"¤j¿ÀÃÉºCºCªº´å¶i¤F´ä¤f.....\n"NOR);
  if(mapp(ex))
  place[index]->set("exits",(mapping)(place[index]->query("exits"))+
  ([ UP_DOOR : base_name(this_object()), ]) );
  else {
    ex=([]);
 ex[UP_DOOR]=base_name(this_object());
    place[index]->set("exits",ex);
  }
  indexp=index;
  index++;
  if(index==sizeof(place)) index=0;
remove_call_out("boat");
close_time=30;
  stay=1;
  call_out("closedoor1",0,"¥¿°±¾a¦b "+place[indexp]->query("short"));
}
void closedoor1(string s)
{
  object this_ship,temp_ship,ob1,ob2;
  mapping ex;
  this_ship=this_object();
  if(close_time>10)
  {
        close_time -=10;
        remove_call_out("closedoor1");
        call_out("closedoor1",10,"°±¾a¦b "+place[indexp]->query("short"));
  }
  else if(close_time>0)
  {
        tell_room(this_object(),"ÁÙ¦³" +HIY+sprintf("%d",close_time)+NOR+"¬í´N­n¥Xµo¤F\n");
        tell_room(place[indexp],"¤j¿ÀÃÉ´N­n¥X´ä¤F!½Ð­n·f­¼ªº®È«È»°§Öª¦¤W¨Ó("+UP_DOOR+").....\n"NOR);
        close_time -=5;
        remove_call_out("closedoor1");
        call_out("closedoor1",5,"°±¾a¦b "+place[indexp]->query("short"));
  } else 
  {
        tell_room(this_object(),HIW"¿ÀÃÉ¾_°Ê¤F¤@¤U...½w½wªº©¹"+place[index]->query("short")+HIW+"«e¶i...\n"NOR);
        // add by nilekil
        ob1=find_object(place[indexp]);
        ob2=present("cancer",ob1); 
        if (!ob2)
        { 
                tell_room(place[indexp],"¤j¿ÀÃÉªº«ÍÅéº¥º¥¨I¤U¥h¤F...\n");
                destruct(this_ship); // Luky
   return;
        } else
        { 
                tell_room(place[indexp],"¤j¿ÀÃÉ¦ù­ÓÃi¸y, ©¹®ü­±²¾°Ê...\n");
                destruct(ob2);
        }
        tell_room(place[indexp],HIR"¤j¿ÀÃÉ½w½wªºÂ÷¶}¤F³°©¤¡A¶}©l©¹"+
                place[index]->query("short")+HIC"²¾°Ê..\n");
        set("long",this_object()->query("ship_long")+HIR"  ¤j¿ÀÃÉ"HIG"²{¦b¥¿¦b«e©¹ "
                +place[index]->query("short")+" ªº³~¤¤...\n\n"NOR);
   ex=this_object()->query("exits");
   if(mapp(ex)) map_delete(ex,DOWN_DOOR);
   ex=place[indexp]->query("exits");
   if(mapp(ex)) map_delete(ex,UP_DOOR);
   place[indexp]->set("exits",ex);
   remove_call_out("closedoor1");
   stay=0;
//call_out("boat",span_time[index],"«e¥¿©¹ "+place[index]->query("short")+"¤¤");
  call_out("swim",5,span_time[index]);
  }
}

