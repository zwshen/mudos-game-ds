#include <ansi.h>
inherit NPC;
void create()
{
        set_name(HIW"武藏野"NOR,({ "wu tan ya","ya","wu" }));
        set("long",
                "他是一位年紀輕輕就刀法高明的扶桑浪人，與天京井和崎顏神\n"
                "結拜為兄弟，合稱為「依賀三傑」。\n"
        );
        set("nickname",HIR"依賀三傑之一"NOR);
        set("age",25);
        set("level",35);
        set("gender", "男性");
        set("str",40);                  
        set("dex",70);                  
        set("con",100);                
        set("int",70);                  
        set("exp",19208);        
        
        set("combat_exp",6000);         
        set("evil",-10);  
               
 set_skill("blade",100);          
        set_skill("parry",100);          
        set_skill("dodge",90);  
        set_skill("perception",35);
        set_skill("combat",100);     


        set("chat_chance",10);
        set("chat_msg", ({
  
  name()+"說道: 弟弟你年紀輕輕武功\就如此高明，不出幾年一定能超越我們的。\n",
  name()+"說道: 不不不!崎顏神他實在太強了!你還要好好練習才可能超越他。 \n",
  name()+"說道: 不過好懷念我們幾個十幾出頭的快樂光陰，真想再戰幾場。\n",
(: command("smile") :),
(: command(":)") :),
(: command("addoil") :),
}) );
        set("chat_chance_combat",60);
        set("chat_msg_combat", ({
              "武藏野興奮的說：好久沒有跟人戰鬥了！就算戰死我也甘心！\n",
         (: command(":)") :),
           }) );
        setup();
        carry_object(__DIR__"wp/japen_blade")->wield();
        carry_object(__DIR__"eq/japen_surcoat")->wear();
        } 

