#include <ansi.h>
inherit NPC;

void create()
{
        set_name("薇雅", ({"Wei Ya","ya","wei" }) );
        set("long", "
一個年輕女子，雙腿修長高眺，長長的秀髮，紮成馬尾躺在小
巧的耳後，明亮的雙眸，秀麗而彎彎的眉毛，溫柔的雙唇，美麗的安置
在勻稱的鵝蛋臉上。身穿淺白色T恤，像世界上最美好的春光。　　　
你開始向她走去，完全忘記去注意她根本沒戴太陽眼鏡！\n");
        set("race", "人類");
        set("gender", "女性"); 
        set("age", 18);
        set("attitude", "friendly");
        set("level", 3);
        set("evil", -999);
        set("combat_exp",2000);
        set_skill("unarmed", 4);
        set_skill("dodge", 10);
        set_skill("parry", 7);  
        set("env/wimpy", 30);        
        set("chat_chance",4); 
        set("chat_msg", ({   
        "薇雅抬起頭靜靜望著天空\n",
        "薇雅轉過頭來向你望了望又望回天空\n",
        (:command(""):),
        (:command(""):),
}) );
        set("chat_chance_combat",160);
        set("chat_msg_combat", ({
        "薇雅尖叫道:阿∼∼阿∼∼阿∼∼\n",
        (:command(""):),
        }) );
        setup(); 
}






