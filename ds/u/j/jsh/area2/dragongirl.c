#include <ansi.h>

inherit NPC;

void create()
{
       set_name(HIY "小龍女" NOR,({"dragon girl","girl"}) );
       set("title",HIC "古墓" NOR);
         set("long",@LONG
 「小龍女」是古墓主人之一，儀態優雅，與徒弟楊過結為夫妻，但
 愛意依舊，不會因為夫婿的不全而冷落他，反而更加愛護，可惜他
 們深居古墓，不然別人知道了，必然表揚之。
LONG    
         );
         set("race", "human");    
         set("unit","隻");
         set("age",45);
         set("level",40); 
         set("max_ap",4100);
         set("combat_exp",500000);         set("attitude", "heroism");    
         set("limbs", ({ "頭部", "腹部","胸部","手部","腳部" }) ); 
         add("addition_armor",150);
         add("addition_damage",200); 
         set("chat_chance_combat", 50);
         set("chat_msg_combat", ({
         (: command("exert girl-sword") :),     
         (: command("exert girl-sword") :),
         (: command("wield sword") :),
         (: command("wield sword") :),
         (: command("wield sword") :),})); 
        set_skill("girl-sword",100);

         setup();
         carry_object(__DIR__"sword3")->wield();
}
void die()
{
        object ob,obj;
        obj=new(__DIR__"/obj/money/coin");
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        if( !ob ) 
 
         {
                 ::die();
                 return;
         }
         message("world:world1:vision",
    HIR"\n\n         啊  ~    ~    ~  "+HIC"小龍女"+HIR"死前對"+ob->name(1)+"哀嚎了幾聲。\n\n"+NOR
         ,users());
         ob->add("popularity",1); //聲望
      message_vision( "$N"+HIR "   臨死前，仍不停的呼喚著楊過...." NOR ,this_object() );
         ::die();
         return;
}

