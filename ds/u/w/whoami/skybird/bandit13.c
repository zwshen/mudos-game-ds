#include <ansi.h>
#include <room.h>
inherit ROOM; 

string *show_msg = ({
HIC+BLK"你聽到一些微小的聲音從你上方的木門傳了過來……\n"NOR,
WHT"隔著一扇門，你實在聽不出來她們在說些什麼……\n"NOR,
HIC"突然間，樓上傳來『碰』的一聲，那些聲音漸漸的消失了•\n"NOR, 
HIG"看來這是個可以出去看看情形的時機了•\n"NOR,
});
void create()
{
 set("short","寨主房");
 set("long",@LONG


LONG);
 set("no_clean_up",0);
 set("light",1);
 setup();

} 

void init()
{
   object me=this_player(),ob=this_object();
   ::init();
   if ( !me->query_temp("block") ) return;
   me->set_temp("msg",1); 
   if ( !me->query_temp("msg") ) return;   call_out("delete_block",40);
}

void delete_block()
{
   object me=this_player(),ob=this_object();
   int i = me->query_temp("msg");
   string msg; 

   if( i > 4 ){
      me->delete_temp("msg"); 
      me->delete_temp("block");
      ob->add("exits",(["westup":__DIR__"bandit11"]));
      call_out("rb",300);
      return;
   } else {
      msg = show_msg[i-1];
      tell_object(me,msg);
      me->add_temp("msg",1);
      call_out("delete_block",6-i);
   }
  return;    
}
 
void rb()
{
   object me=this_player(),ob=this_object();
   ob->delete("exits","westup");
   return;    
}

int valid_leave(object me, string dir)
{
  if( !me->query("class") && me->query_temp("block") && dir == "westup" )
  {
        return notify_fail("你聽到了不少人的談話聲，最好還是等等再上去吧•");
  }
  else if( !me->query_temp("block") && dir == "westup" )
  {
    message_vision("$N偷偷摸摸地往上離開•\n",me);
    return ::valid_leave(me, dir);
  }
  return ::valid_leave(me, dir);
}

