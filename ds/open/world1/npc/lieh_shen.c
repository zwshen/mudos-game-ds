#include <ansi.h>

inherit NPC;

void create()
{
        set_name("烈昇", ({ "lieh shen","shen" }) );
        set("race","human");
        set("gender", "男性");
        set("level",43);
        set("age",45);
        set("evil",-20);
        set("title",HIR"聖炎龍使"NOR);
        set("long",@LONG
眼神炯炯發光，一臉霸氣的中年男子，壯碩的身材，發達的
肌肉，在在顯示出這個人的修為不弱。直到你看到他身上所
披的披風上印有八歧炎龍的標誌，才知道他就是聖炎使者之
首。
LONG
);
        setup(); 
        carry_object(__DIR__"../eq/bc_cloak")->wear();
        carry_object(__DIR__"../wp/soon_flame")->wield();
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
   if(!me || !target) return 0;
    if(random(4)) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance/2) > tdex+tcon)
    {
      message_vision("\n"
                    +HIR"$N一聲暴喝，全身上下都冒出火來，宛如一個火人......\n"
                    +"$N迅速地往$n撞上去，$n全身上下也都著火了！！\n"
                    +"$n被火燒得遍體鱗傷......\n\n"NOR
                    ,me,target);
      target->receive_damage("hp",200+random(150), this_object());
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +HIR"$N一聲暴喝，全身上下都冒出火來，宛如一個火人......\n"
                    +"$N迅速地往$n，但是$n在千鈞一髮之際往右急閃......\n"
                    +"$n雖然閃過$N的正面撞擊，但卻被$N身上的火灼傷了......\n\n"NOR
                    ,me,target);      
      target->receive_damage("hp",100+random(50), this_object());
      return 1;
    }
}

