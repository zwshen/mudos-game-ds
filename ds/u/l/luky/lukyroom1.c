// Room /u/l/luky/room/lukyroom1
#include <ansi.h>  //­Y­n¥Î¦³ÃC¦âªº¶·¥[¦¹¦æ
#include <room.h>  //­n¥[ªù­n³o¤@¦æ
#include <path.h>
inherit ROOM;
inherit DOOR;

void create()
{
set("short",HIG"Às½¼Ác´Þ¤¤¤ß"NOR);
set("long",
HIC"\n                  ¢b¢c¢d¢e¢f¢g¢h¢i¢i¢h¢g¢f¢e¢d¢c¢b
"HIB"                  ¢i¢i¢i¢i¢i¢i"HIY"Às½¼§O¹Ö"HIB"¢i¢i¢i¢i¢i¢i             "HIG"¢¨¢©
"HIB"                   ¢m         "HIR"ùúùÞùÞùû"HIB"          ¢m"HIG"   ¢¨¢©     ¢¨¢i¢©
"HIC"     ¢b¢d¢e¢f¢g¢h¢i"HIB"¢m "HIR"ùúùÞùû  ùàùäùäùâ  ùúùÞùû"HIB"  ¢m"HIG"  ¢¨¢i¢©   ¢¨¢i¢i¢©
"HIB"      ¢m           ¢m"HIR" ùàùáùâ  ùø    ùø  ùàùáùâ"HIB"  ¢m"HIG" ¢¨¢i¢i¢© ¢¨¢i¢i¢i¢©
"NOR+YEL"ùáùáùáùáùáùáùáùáùá"HIB" ¢m"HIR" ùüùäùý  ùø  ¡óùø  ùüùäùý"HIB"  ¢m"HIG"¢¨¢i¢i¢i¢©¢i¢i¢i¢i¢i¢©
"NOR+YEL"ùøùøùøùøùøùøùøùøùø"HIB" ¢m"HIR"         ùø    ùø"HIB"          ¢m"HIG"    ùø        ùø
"NOR+YEL"ùøùøùøùøùøùøùøùøùø"HIB" ¢m_________"HIR"ùãùùùùùå"HIB"_________ ¢m"HIG"    ùø        ùø
"NOR+GRN"^^^^^^^^^^^^^^^^^^^                             ^^^^^^^^^^^^^^^^^^^^^^^
"NOR);
set("light",1);
set("objects",([
]));

set("exits",([  
"west" : __DIR__"workroom1",
]));
set("hide_exits",([  
]));

set("no_clean_up", 1);
create_door("west","¬õ¦â¤jªù","east",DOOR_LOCKED,"redkey");
setup();
}

void init()
{
 add_action("do_ip","ip");
}

int do_ip(string arg)
{
 object *player;
 int x,i,ip1,j;
 string list,temp;
 
 list="\n";
 player=users();
 x=0;
 for(j=127;204>j;j++)
 {
 for(i=0;sizeof(player)>i;i++)
 {
  sscanf( query_ip_number(player[i]),"%d.%s",ip1,temp);
  if(ip1==j) list+=sprintf( "%12s (%12s) %s \n",player[i]->query("name"),player[i]->query("id"),query_ip_number(player[i]));
 }
}

 write(list);
 return 1;
}
