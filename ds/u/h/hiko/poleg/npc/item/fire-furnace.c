/*此檔案是參照kkeenn 的lovecity furnace*/
#include <ansi.h>
inherit ITEM;
void create()
{
  set_name(HIM"火爐"NOR,({"fire furnace","furnace"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {

    set("long",@LONG  
    這是專門為喜歡自己動手作料理的人所放置的器具，可以
依個人喜好而加入料理，而且煮法多變，是許多來此店的人的
最愛，也是來這裡的人常使用的一種方式，內部的溫度十分適
中且具有良好隔熱措施，可以說是廚房的最佳用具，據說是店
主從西域帶回來的，可以說是在中原已經絕無僅有，老饕們都
熱愛於此道，可見此爐之不凡。
( 使用方法: cook)
LONG
);
 }
  set("no_sac", 1);
  set("no_get", 1);
  set("no_clean_up",1);
  set("value", 300);
  set_max_encumbrance(999999);
  setup();
}

void init()
{
  add_action("do_cook","cook");
}

int do_cook()
{
  object ob = this_object(), *obs,me;
  me = this_player();
  obs = all_inventory(ob);
       if (me->query("ap")<40)
                return notify_fail ("你的體力不夠集中精神作料理了喔!");  
       if (me->is_busy())
                return notify_fail ("你的動作還沒完成！\n");
        if( !sizeof(obs) ) 
                return notify_fail("沒有東西在內，怎樣煮???\n"); 
        if (ob->query_temp("make_food")>0)
                return notify_fail ("火爐有人在使用了！\n");
                ob->set_temp("make_food",1);
   message_vision(HIW "$N把料理處理好，眼睛似乎冒著奮發的火，迅速的開始動手∼\n\n" NOR, me);
        tell_object(me, HIW "器具準備好後，隨即就開始大顯身手展現廚藝了.....\n\n" NOR );
        tell_object(me, HIY "鏘鏘鏘∼∼剁剁剁∼∼∼啪滋啪滋∼∼\n\n\n" NOR );
        me->disable_player_cmds("你正在作料理。\n");
        me->set_temp("is_busy/making","你正在作料理。");
        me->start_busy(10);
        call_out("make1",3,me);
        call_out("make2",8,me);
        call_out("makefood",15,me);
        return 1;

}
 void make1(object me)
{
        if(!me) return;
    tell_object(me,HIG"你漸漸進入了狀況，作料理越來越拿手了∼\n"NOR);
        me->add("ap",-20);
        return;
}

void make2(object me)
{
        if(!me) return;
        tell_object(me,HIB"你對自己的手藝蠻滿意，覺得自己可以改行當廚師了∼∼ｚｚｚ\n"NOR);
        me->add("ap",-20);
        return;
}
int makefood(object me)
{ 
  object ob = this_object(), *obs;
  int i,n,x,index = 0;
  me = this_player();
  obs = all_inventory(ob);
 for(i=0;i<sizeof(obs);i++)
  {
    if(obs[i]->query("id") == "sifu meat") index += 13;
    if(obs[i]->query("id") == "liuye meat") index += 14;
    if(obs[i]->query("id") == "sandling meat") index += 15;
    if(obs[i]->query("id") == "shark meat") index += 16;
    if(obs[i]->query("id") == "yue meat") index += 18;
    if(obs[i]->query("id") == "grig meat") index += 20;
    if(obs[i]->query("id") == "flyfish meat")  index += 21; 
  }
  
  if(random(10) > 4)
    {
        switch(index) 
        {
        case 28..41 :                      
     message_vision("$N在細細調味之下，作出了一道"+ HIY"雙魚拼盤"NOR +"。  \n",me);
                           me->add("ap",-30);
                           new(__DIR__"food/shugin-pinpan")->move(ob); 
                           break;
        case 42..57 :
        message_vision("$N全力專研食譜之後，作出了一道"+ HIY"三味蒸魚"NOR +"。  \n",me);
                           me->add("ap",-30); 
                           new(__DIR__"food/sanwe-jinin")->move(ob);                           
                           break;
                       
        case 58 :                           
        message_vision("$N用出了家傳秘方，作出了一道"+ RED"紅燒糖醋魚"NOR +"。 \n",me);
                           me->add("ap",-40);
                           new(__DIR__"food/hungsa-tantsu")->move(ob);
                           break;
        case 59 :
        message_vision("$N全力研究下，完成一道"+ RED"麻辣魚片"NOR +"\n\n",me);
                           me->add("ap",-40);
                           new(__DIR__"food/malain-pan")->move(ob);
                           break;
        case 63 :
        message_vision("$N全心投入於烹煮，作出了一道"+ HIG"珍珠翡翠魚"NOR +"。 \n\n",me);
                           me->add("ap",-40);
                           new(__DIR__"food/jansufatre-fish")->move(ob);
                           break;
        case 75..76 :
        message_vision("$N小心的處理和料理，作出了一道"+HIC"魚越龍門"NOR +"。 \n\n",me);
                           me->add("ap",-50);
                           new(__DIR__"food/inyelongment-fish")->move(ob);
                           break; 
        case 81..90 :
        message_vision("$N很有耐心的慢慢熬煮，作出了一道"+HIM"五色香魚"NOR +"。 \n\n",me);
                           me->add("ap",-50);
                           new(__DIR__"food/wuces-fish")->move(ob);
                           break; 
        case 96..104 :
        message_vision("$N展現驚人的廚藝，作出了一道"+HIY"六川祥魚"NOR +"。 \n\n",me);
                           me->add("ap",-60);
                           new(__DIR__"food/liusug-fish")->move(ob);
                           break;
        case 117 :
        message_vision("$N集合全部經驗，作出了一道"+HIR"宮廷密魚"NOR +"。 \n\n",me);
                           me->add("ap",-70);
                           new(__DIR__"food/gontinmi-fish")->move(ob);
                           break;        default :  
        message_vision("$N手藝不夠純熟，作出了失敗作品。 \n\n",me);
                           me->add("ap",-20);
                           new(__DIR__"food/failfood")->move(ob);                           break;
        }
        ob->add_temp("make_food",-1);
        me->enable_player_cmds();
        me->delete_temp("is_busy/making");     
           for(i=0;i<sizeof(obs);i++)
                destruct(obs[i]);
                return 1;
     }
   else    
      { 
      message_vision("$N手藝不夠純熟，作出了失敗作品。 \n\n",me);
        new(__DIR__"food/failfood")->move(ob);
        me->add("ap",-20);
        ob->add_temp("make_food",-1);
        me->enable_player_cmds();
        me->delete_temp("is_busy/making");                   
        for(i=0;i<sizeof(obs);i++)
                destruct(obs[i]);
                return 1;
      }    

}


  














