#include <ansi.h>
#include <room.h>
inherit ROOM; 
inherit DOOR;

void callmob1();
void callmob2();
void callmob3();
void callmob4();
void end_war();
void start_war();

string *place=({"bandit1","bandit2","bandit3","bandit4","bandit5",
                "bandit6","bandit7","bandit8","bandit9","bandit10"
               });
string *bandit=({"bandit_lackey_1","bandit","brigand","ringleader"});

void create()
{
 set("short","寨門");
 set("long",@LONG
你終於走到小路的盡頭了, 眼前是一個大大的寨門, 只見兩
旁都是一些巡邏中的嘍囉, 使你感到你的生命有些危險.
LONG);
 set("exits",([ 
               "enter":__DIR__"bandit1", 
               "west":__DIR__"ten5",
    ])); 
 set("objects", ([__DIR__"npc/bandit_lackey" : 1+random(4),
    ]));

 set("no_clean_up",0);
 set("light",0);
 setup();
 create_door("enter","厚重鐵門","out",DOOR_LOCKED,"nokey");
}

varargs int unlock_door(string dir, int from_other_side)
{
        object env,npc,me=this_player();
        if( :: unlock_door(dir, from_other_side) )
        {

        env=this_object();
        if(!objectp(npc=find_living("Ten-mount_bandit") ) && env->query("Ten-mount_bandit")==1 )
           env->delete("Ten-mount_bandit");
        if( env && env->query("Ten-mount_bandit")!=1 )
        {
      message("world:world1:vision",

HIY"\n\t英勇的"+me->query("name")+"攻破了山寨大門，往山寨中心前進！！\n"NOR,users() );
          env->start_war(1);
          env->set("Ten-mount_bandit",1);
        }        
        }
        return :: unlock_door(dir, from_other_side) ;
} 

void start_war()
{
        int i;
        object g;
//小嘍囉(bandit's lackey)  -> 15 隻
//悍匪(bandit)             -> 10 隻
//土匪(brigand)            ->  7 隻
//小頭目(ringleader)       ->  5 隻
//----------------------------------
//合計(total)              -> 37 隻

        for (i=0;i<=15;i++)
        {
        g=new(__DIR__+"npc/"+bandit[0]);
        g->move(__DIR__+place[random(sizeof(place))] );
        } 

     call_out("callmob1",40);
    return;
}
void callmob1()
{
        int i;
        object g; 
 
        for (i=0;i<=10;i++)
        {
        g=new(__DIR__+"npc/"+bandit[1]);
        g->move(__DIR__+place[random(sizeof(place))] );
        } 

     call_out("callmob2",40);
     return;       
}
void callmob2()
{
        int i;
        object g; 
 
        for (i=0;i<=7;i++)
        {
        g=new(__DIR__+"npc/"+bandit[2]);
        g->move(__DIR__+place[random(sizeof(place))] );
        } 
    call_out("callmob3",40);
     return;
}
void callmob3()
{
        int i;
        object g; 
 
        for (i=0;i<=5;i++)
        {
        g=new(__DIR__+"npc/"+bandit[3]);
        g->move(__DIR__+place[random(sizeof(place))] );
        } 
     call_out("end_war",60);
     return;
}

void end_war()
{
        object npc;
        object e,s,n,w;
        if(objectp(npc=find_living("Ten-mount_bandit") ) )
        {
                 if(!environment(npc)) destruct(npc);
                  call_out("end_war",30,0);
        }
        else {
                message("world:world1:vision",
        HIW"\n\t十萬山寨群賊一哄而散，整座山寨宛若空城•\n\n"  NOR
                ,users() );
          this_object()->delete("Ten-mount_bandit");
        }
return;
}

int valid_leave(object me, string dir)
{
  mapping doors;
  doors = environment(me)->query_doors();
  if( dir=="enter" && doors[dir]["status"] == DOOR_OPENED )
  { 
    message_vision("\n『碰』的一聲，$N身後的厚重鐵門突然被關上了•\n"NOR,me);
    lock_door(dir);
    return 1;
  }
  else if( dir=="enter" && !doors[dir]["status"] == DOOR_OPENED ) 
    return notify_fail("門還沒開喔!\n");
  else if(dir=="west") return 1;
  else return 0;
}

