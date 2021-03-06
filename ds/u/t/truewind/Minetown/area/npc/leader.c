#include <ansi.h>
inherit NPC;

void create()
{
        set_name(HIR"怪手"NOR"威廉", ({"Armstrong william","william"}) );
        set("long",@LONG
這男人一臉大鬍子，滿身橫肉，是由星聯總部派來，作為礦村的總領
，他穿著星聯的藍色制服，神色驕傲。你注意到他的肩膀特別的壯碩
，隨時可以勒死一隻熊的樣子，難怪叫做"怪手"。
LONG
);
        set("race", "人類");
        set("age", 205);
        set("title","礦村村長");
        set("level", 40);
        set_skill("combat",70);
        set("chat_chance", 10);
        set("chat_msg", ({
        (: command("say 星聯派我來這裡差不多兩個月了...。") :),
        (: command("say 然後附近發生了不少奇怪的事情。") :),
        (: command("say 有幾個礦工翹班去喝酒，都莫名其妙的不見了!?") :),
        (: command("say 還有幾部礦車不知道怎樣在修車廠被搞丟了....") :),
        (: command("say 聽說機車老麥跟酒廠的比利好像知道些什麼...不過都沒吐露...") :),
        (: command("think") :),
        }));
        set("talk_reply","如果你與我交談 <say> 會發現意想不到的情報唷！\n");
        carry_object(__DIR__"wp/armfist.c")->wield();
        setup();
}

int special_attack(object me,object target,int hitchance)
{
    int tdex,tcon; 
    if(!me || !target) return 0;
    if(random(100) > 50) return 0;
    tdex=target->query_dex();
    tcon=target->query_con();
    if(random(hitchance/2) > tdex+tcon)
    {
      message_vision("\n"
                    +WHT"$N拔腿往$n衝來，腳下捲起漫天塵沙！\n"
                    +HIW"$n要閃也來不及，胸口接下一記$N全力正面撞擊！\n"
                    +"$n胸口被猛烈重擊，猛然吐出一大口鮮血！\n\n"NOR
                    ,me,target);
      target->receive_damage("hp",100+random(30), this_object());
      target->receive_wound("body",5);
      return 1; 
    }
    else
    {
      message_vision("\n"
                    +WHT"$N拔腿往$n衝來，腳下捲起漫天塵沙！\n"
                    +HIW"$n閃躲不及，整個人被撞歪的倒在地上！\n\n"NOR
                    ,me,target);      
                    target->receive_damage("hp",random(50), this_object());
                    return 1;
    }
}

