#include <ansi.h>
inherit NPC;
void create()
{
set_name("邱奕捷",({"chiu yai je","chiu","yai","je"}));
set("long",@LONG
這是一位退隱江湖的傳奇人物, 他的武功無師自通, 十八歲時大鬧
江湖, 武功由以劍法見長, 一身索極劍法更是爐火純青後來經過著
名的羊腸道混戰, 一人獨滅黑道頗負威名的十萬大山群盜, 一舉聲
名大噪, 然而, 如今他以三六歲退隱江湖關於他為何如此之強, 最
可信的是他似乎和某個巫師有相同的名字....
LONG
    );
 set("attitude","peaceful"); 
 set("title",HIR"隻手遮天"NOR);
 set("age",36);
 set("gender","男性");
 set("level",30);
 set_skill("sword",100);
 set_skill("sorgi_sword",100);
 map_skill("sword","sorgi_sword");
 set_skill("force",60);
 set_skill("parry",70);
 setup();
 carry_object(__DIR__"eq/sword")->wield();
 carry_object(__DIR__"eq/cloth")->wear();
}

