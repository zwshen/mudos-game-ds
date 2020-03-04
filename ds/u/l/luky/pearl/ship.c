//boat.c 
//update by luky. 1998.11.12
#include <ansi.h>
#include <path.h>
#define TIME_SPAN tt
#define UP_DOOR "climb"
#define DOWN_DOOR "out"
inherit ROOM;
int index=1;
int close_time;
int indexp=0;
int stay=1;
string *place=({
LUKY+"pearl/sand2",
LUKY+"pearl/pearl_32",
});
int tt=30;
void start();
void boat(string);
string query_filename()
{
  return place[index];
}
int getall()
{
  int i;
  for(i=0;i<sizeof(place);i++)
    if(stay)
      write(sprintf("%2d %10s %s %s \n",
           i+1,
           i==indexp ? HIY"¥Ø«e°±¦b->"NOR:"  ",
           place[i]->query("short"),
wiz_level(this_player())>=wiz_level("(admin)")?"=> ("+place[i]+")":"
"
             ));
     else
      write(sprintf("%2d %8s %s %s \n",
           i+1,
           i==index ? HIY"¤U¤@¯¸->"NOR:" ",
           place[i]->query("short"),
 wiz_level(this_player())>=wiz_level("(admin)")?"=> ("+place[i]+")":"
"
             ));

  return 1;
}

void create()
{
//seteuid(getuid());
set("short","[1;31m¤j¿ÀÃÉ[0m");
set("name","[1;31m¤j¿ÀÃÉ¹[m");
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
    message_vision(HIG"$N[1;32mµn¤W¤F"+this_object()->query("name")+"¡C\n"NOR,me);
}

int getman()
{
  object *inv;
  int i,all;
  all=0;
  inv=all_inventory(this_object());
//  for(i=0;i<sizeof(inv);i++)
//  if(userp(inv[i]))all++;
  all=sizeof(inv);
  return all;
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
  s=sprintf(HIR"¤j¿ÀÃÉ¤w¨ì¹F [1;34m%s[0m\n"NOR
  HIC"¥Ø«e¿ÀÃÉ¤Wªº®È«ÈÁ`¦@¦³ %d ­Ó¤H\n"NOR, (place[index])->query("short")
  , getman());
  set("long",HIG"§A¦Vµ¡¥~±æ¥h¡A»®µMµo²{"+s+"\n\n "HIY+"list"NOR+"¥i¬d¬Ýªu³~°±¾aªº¯¸³á\n "NOR);
  write(s+"§A¬Ý¨ìµ¡¥~ªº´ºª«¬O:\n"+place[index]->query("long")+"\n");
  write(HIW"­nÂ÷¶}ªº®È«È½Ð±Æ¶¤¤U¨®(out)..\n"+NOR+"\n");
  setup();

  ex=place[index]->query("exits");
// add by Nilekil
        ob1=new(LUKY+"pearl/tempship.c");
        ob2=find_object(place[index]);
        ob1->move(ob2);
  tell_room(place[index],
HIC"[1;31m¤j¿ÀÃÉ[1;36mºCºCªº´å¶i¤F´ä¤f.....\n"NOR);
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
close_time=20;
  stay=1;
  call_out("closedoor1",0,"¥¿°±¾a¦b "+place[indexp]->query("short"));
}
void closedoor1(string s)
{
  object this_ship,temp_ship,ob1,ob2;
  mapping ex;
this_ship=this_object();
  if(close_time>0)
{
//write("ÁÙ¦³" +HIY+sprintf("%d",close_time)+NOR+"¬í´N­n¥Xµo¤F\n");
tell_room(place[indexp],"¤j¿ÀÃÉ´N­n¥X´ä¤F!½Ð­n·f­¼ªº®È«È»°§Öª¦¤W¨Ó("+UP_DOOR+").....\n"NOR);
close_time -=10;
remove_call_out("closedoor1");
call_out("closedoor1",10,"°±¾a¦b "+place[indexp]->query("short"));
} else 
{
write(HIW"¿ÀÃÉ¾_°Ê¤F¤@¤U...½w½wªº©¹"+place[index]->query("short")+HIW+"«e¶i...\n"NOR);
// add by nilekil
ob1=find_object(place[indexp]);
ob2=present("cancer",ob1); 
if (!ob2)         { 
                tell_room(place[indexp],"¤j¿ÀÃÉÄ±±o¤Ó²Ö..¸ú°_¨Ó¤£¤W¯Z¤F!!\n");
         destruct(this_ship); // Luky
        }
        else { 
                tell_room(place[indexp],"¤j¿ÀÃÉ¦ù­ÓÃi¸y, ©¹®ü­±²¾°Ê...\n");
                destruct(ob2);
        }
tell_room(place[indexp],HIR"¤j¿ÀÃÉ[1;36m½w½wªºÂ÷¶}¤F´ä¤f¡A¶}©l©¹"+
place[index]->query("short")+HIC"²¾°Ê..[0m\n");
set("long","§A²{¦b¥¿¥Ñ "+place[indexp]->query("short")+
   " ¦æ¾p©¹ "+place[index]->query("short")+" ³~¤¤...\n"+
   "¥i¥´ "+HIY+"list"+NOR+" ¨Ó¬d¬Ýªu³~¸g¹Lªº¯¸\n\n");
   ex=this_object()->query("exits");
   if(mapp(ex)) map_delete(ex,DOWN_DOOR);
   ex=place[indexp]->query("exits");
   if(mapp(ex)) map_delete(ex,UP_DOOR);
   place[indexp]->set("exits",ex);
   remove_call_out("closedoor1");
   stay=0;
call_out("boat",TIME_SPAN,"¥¿¶}©¹ "+place[index]->query("short")+"¤¤");
  }
}
