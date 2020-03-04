
#include <ansi.h>
inherit NPC;

void create()
{
        set_name("神父",({"god-father","father"}) );
        set("long",
"一位莊嚴的神父，他正在講道，仔細一瞧，原來是旁邊的投影機產生的幻影。 \n"
);
        set("gender","男生");
        set("age",30);
        set("level",5);
        set("race","人類");
        set("chat_chance",1);
        set("chat_msg",({
"神父說道： 我們的天父，為你的名受顯揚；\n",
"神父說道：願你的國來臨;願你的旨意奉行在人間，如同在天上。\n",
"神父說道：求你今天賞給我們日用的食糧；\n",
"神父說道：求你寬恕我們的罪過，如同我們寬恕別人一樣；\n",
"神父說道：不要讓我們陷於誘惑，但救我們免於凶惡。\n",
"神父說道：『亞孟…』\n",
        })      );
    set_temp("float",1); 
        setup();
}