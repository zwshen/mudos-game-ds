#include <ansi.h>
inherit ROOM;

int query_pool_npc();

void create()
{
  set("short", HIB"水寒星洞"NOR);
  set("long", @LONG 
這是一窟幽暗的水洞，水洞上方吊著一條條純白的鐘乳石，滴著小小
水珠，在兩旁，豎立著數條紫水晶，每每互相輝印，照亮水洞的每個大小
角落。中間有一潭水池，潭邊似乎有什麼東西的樣子。
LONG); 
  set("item_desc",([ 
      "水池":"深藍無底的水池，在水池邊緣，竟刻著『水寒星洞』四個 [大字]，且旁邊插著一塊 [木牌]。\n",
      "大字":"『水 寒 星 洞』。 \n",
      "木牌":"一塊木製的牌子，上面寫著 [請勿丟擲火紅果！throw xxx in pool]。\n",
     ]) );
  set("exits", ([ /* sizeof() ==  */ 
      "east" : __DIR__"room19",
     ]));
  set("no_light",1); 
  set("no_recall",1);
  setup();
}

void init()
{
  add_action("do_throw","throw");
}

int do_throw(string arg)
{
int i;
object me,x,z;          
  me = this_player();
  if( query_temp("throw")==1) return notify_fail("剛剛有人丟過了。\n");
  if(!arg || arg!="fruit in pool")
        return notify_fail("你要丟擲什麼?\n");
  if(!objectp(z=present("fire fruit",me) ) )
    return notify_fail("你沒有東西可以丟啊 ? \n");
  if( query_pool_npc() >0 )
        return notify_fail("你被擋住，無法接近水池去丟東西。\n");

  message_vision(HIW"$N丟出一顆"HIR"火紅果。\n"NOR,me); 
  this_object()->add_temp("throw", 1); 
  call_out("stop_thu", 10, this_object());
  destruct(z);

  me->start_busy(2);
  i = random(8);
  while( i == query_temp("last_mob") )  
    i = random(8);    // 不會叫出與之前重覆的npc
  
  switch (i)
  { 
    case 0:
         write("你忽然聽到一聲：你在幹什麼！！！不是都說不能丟火紅果了！沒看到我立的牌子嘛！！\n");
         tell_object(this_object(), "子黃丹說：好小子！！！看我怎麼教訓你！\n");
         x = new(__DIR__"npc/dan");
         x->move(this_object());
         x->kill_ob(this_player()); 
         me->start_busy(8);
         set_temp("last_mob",0);
         break;
    case 1:
         tell_object(this_object(), "水池中忽然激起一陣陣澎湃的水花！。\n"); 
         message("world:world1:vision", 
           HIW"\n\t千年神獸•『玄武神龜』重出水池，忽然天降甘霖，久不消退。\n"NOR,users());
         message_vision("玄武神龜露出一雙水汪汪的大眼睛，似乎想跟你討東西吃••\n",me);
         x = new(__DIR__"npc/turtle"); 
         x->move(this_object());  
         set_temp("last_mob",1);
         break;
    case 2:
         tell_object(this_object(), "忽然一道黑影，疾呼而過，天空彷彿暗了一半••\n");
         message("world:world1:vision", 
           HIR"\n\t"+me->name(1)+"敵逢百年巨鵰，雙方展開一場激烈廝殺！！\n\n"NOR,users());     
         x=new(__DIR__"npc/chisel");
         x->move(this_object());    
         x->kill_ob(this_player()) ;
         set_temp("last_mob",2);
         break;
    case 3:
         tell_object(this_object(), "當火紅果還在空中時，『咦！』不見了，只聽見一陣怪聲•••\n");
         message("world:world1:vision",
           HIG"\n\t妖精商：咯咯咯咯....我有很多寶貝，不是你們人類買得起的...咯咯咯咯..\n\n"NOR,users());      
         x=new(__DIR__"npc/elf");
         x->move(this_object());   
         this_player()->start_busy(2);
         set_temp("last_mob",3);
         break;  
  case 4:
         tell_object(this_object(), "火紅果高高的飛在空中，『咚』的一聲，掉進的水裡，並沒產生什麼異狀\n\n");
         set_temp("last_mob",4);
         break; 
    case 5:
         tell_object(this_object(), "池中激出朵漂亮的水花，一波波漣漪往四週擴散而去\n"       
               "突然！池中浮現一條血紅的身影！\n");  
         message("world:world1:vision", 
           HIY"\n\t【水寒星洞】"+HIR"殘暴血蛟，再出江湖，水洞生物，無一倖免。\n"+NOR,users());                                                
         x=new(__DIR__"npc/snake");
         x->move(this_object()); 
         x->kill_ob(this_player());
         set_temp("last_mob",5);
         break; 
    case 6:
        tell_object(this_object(), "池中激出朵漂亮的水花,一波波漣漪往四週擴散而去\n"
               "突然!池中浮現一條黃金的身影！\n"); 
         message("world:world1:vision", 
           HIC"\n【動作】"+HIY"麒麟魚(Chi lin-fish)"+HIC"對著大家大聲喊道︰Ｈｅｌｌｏ！大家好∼∼ :D。\n"+NOR,users()); 
         x=new(__DIR__"npc/chi-lin-fish");
         x->move(this_object()); 
         set_temp("last_mob",6);
         break; 
    case 7:
         message("world:world1:vision",HIG"\t南宮世家"HIR"惡棍 "HIW"南宮無雙"HIR"，重出江湖！！\n"
HIW"\n\t南宮鐵心與問天"HIR"說道：江湖必定再引起一陣血光之災！！\n\n"NOR,users()); 
         x=new(__DIR__"npc/master_nan");
         x->move(this_object()); 
         set_temp("last_mob",7);
  }  

  return 1;
}

void stop_thu()
{
        // 刪除丟水果記錄
  delete_temp("throw"); 
  return;
}

int query_pool_npc()
{
  object pool_npc;

  while( objectp(pool_npc = find_living("pool_npc")) )
  {
    if( environment(pool_npc) ) break;

    destruct(pool_npc);
  }
  
  if( objectp(pool_npc) ) return 1;
  return 0;
}

