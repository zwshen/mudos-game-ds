#include <ansi.h>
inherit NPC;

object *item = ({ /*-----暫定的ITEM-----*/
        "/open/world1/tmr/area/npc/obj/soup",
        "/open/world1/ksj/east_island/npc/eq/genki-pill",
        "/open/world1/tmr/area/npc/obj/manto",
});
void msg();

void create()
{
        set_name("守衛的亡魂", ({ "guard soul","guard","soul" }) ); 
        set("level",5);
        set("age",100);
        set("long","負責守護通道的士兵。\n");
        set_temp("float",1);
        set("no_fight",1);
        set("talk_reply","可以幫我個忙嗎？");
//        set("inquiry/幫忙","我的肚子好餓好餓阿...你可以幫我帶吃的東西來嗎？\n");
        set("chat_chance", 20);
        set("chat_msg", ({
        (: msg() :),
        }));
        setup(); 
//        set_living_name("FSTATUE");
 }

void relay_say(object me, string str)
{
   object ob,citem;

   ob = this_object();
   citem = new(item[random(3)]);

   if( !userp(me) ) return;
   if( me == this_object() ) return;

   if(ob->is_busy())
   { return; }

   if( strsrch(str,"吃東西") != -1 )
   {
      message_vision("$N說: 我好久沒有吃東西，肚子好餓阿！\n\n",ob);
      message_vision("$N認真思考..."+HIY"吃什麼"NOR+"好呢？！\n",ob);
      return;
   }

   if( strsrch(str,"不可以") != -1 || strsrch(str,"不行") != -1 || strsrch(str,"不要") != -1)
   {
      message_vision("$N回答說: 幹...誰要你多事！\n\n",ob);
      return;
   }

   if (strsrch(str,"吃什麼") != -1 )
   {
      if(ob->query("item_name"))
      {
          if(ob->query("eat_ok"))
          {
             message_vision("$N說: 我已經吃飽了阿！\n",ob);
             return;
          }
          else
          {
             message_vision("$N說: 剛不是說過了...我想要吃"+ob->query("item_name")+"("+ob->query("item_id")+")阿！\n",ob);
             return;
          }
      }

      message_vision("$N說: 我想要吃"+citem->query("name")+"("+citem->query("id")+")...你可以幫我帶來嗎？\n\n",ob);
      message_vision("$N說: 如果你幫我這個忙，我就幫你個忙...嘿嘿\n",ob);
      ob->set("item_name",citem->query("name"));
      ob->set("item_id",citem->query("id"));
      ob->set("eat_no",1);
      return;
   }

   if(strsrch(str,"入口") != -1)
   {
      message_vision("$N說: 你想找入口？哈哈...你是找不到的！\n\n",ob);
      command("knife soul");
      return;
   }

   if(strsrch(str,"那個東西") != -1)
   {
      message_vision("$N說: 那個東西呀....嘿嘿我可是藏的好好的！\n\n",ob);
      message_vision("$N說: 不過我忘記藏在哪了耶...XD\n",ob);
      return;
   }
}

void msg()
{
   object ob;
   ob = this_object();
   switch( random(5) )
   {
      case  0: 
            message_vision("$N不停哀嚎...好想"HIG"吃東西"NOR"阿...\n",ob);
            break;
      case  1:
            message_vision("$N自言自語: 那個"HIY"入口"NOR"...哈哈...嘿嘿...\n",ob);
            break;
      case  2:
            message_vision("$N奸笑幾聲...嘿嘿..."HIY"那個東西"NOR"應該還在。\n",ob);
            break;
   }
  return;
}

int accept_object(object me,object ob)
{
   object obj;
   obj = this_object();

   if(ob->name() == obj->query("item_name") && obj->query("eat_no"))
   {
         if(obj->is_busy())
         {
            command("whisper "+me->query("id")+" 請你等一下。");
            return 1;
         }

     command("say 沒錯沒錯！就是這個！");
     message_vision("只見$N一口把"+ob->name()+"塞到嘴巴裡...\n\n",obj);
     message_vision(HIR"$N抱頭大喊: 太∼好∼吃∼啦∼∼\n\n"NOR,obj);
     message_vision("$N跳著說: 你想找入口是吧...我陪你找吧！\n",obj,me);
     message_vision("[$N開始跟著$n。]\n",obj,me);
     obj->delete("eat_no");
     obj->set("eat_ok",1);
     obj->delete("chat_msg");
     me->start_busy(2);
     destruct(ob);
     call_out("follow",1,me);
     return 1;
   }
   else
   {
     message_vision("$N說: 給我"+ob->name()+"幹嘛？\n",obj); 
     message_vision("[$N並不想要你的東西。]\n",obj); 
     return notify_fail("");
   }
  return 1;
}

int follow(object me)
{
   object ob;
   ob = this_object();
   ob->set_leader(me);           //follow me
   call_out("follow_none",200,ob);
   return 1;
}

int follow_none(object ob)
{
   command("say 怎麼搞的這久還沒到？不去拉！");
   message_vision("[$N離開了。]\n",ob); 
   destruct(ob);
//     ob->set_leader(0);        //follow none
//     ob->delete("eat_ok");
//     ob->delete("item_name");
//     ob->delete("item_id");
//     ob->move(__DIR__"room5");
   return 1;
}
