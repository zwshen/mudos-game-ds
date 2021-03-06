/* write by -Acme-
   update by -Acme-
*/

#include <ansi2.h>
inherit NPC;
void create()
{
    set_name( "天殘邪佬", ({ "tan chan xie","tan","chan","xie", "__GUARD__" }) );
    set("level",65);
    set("combat_exp",5500);
    set("evil",99);
    set("long", @Long
他是幽冥地窖中的大老，他強若天神，不可一世，他與正派人士
的鬥爭，從未止歇，經過無數的大小戰爭，戰無不克，他已成為
武林中的霸主，正派人士對他都頗為忌憚，許多自成一格的掌門
人，率領著門徒，來圍勦幽冥地窖，卻落得屍骨無存。
Long);
    set("age",100);
    set("gender","男性");
    set("title",HIR"【幽冥惡王】"NOR);
    set("Merits/wit",0);
    set("int",40);
    set_skill("sword",110);
    set_skill("dodge",110);
    set_skill("parry",110);
    set("talk_reply","不必了，只要你不去動我的珍寶就行了！我生平最恨人亂動我的寶物了。\n");
    set("inquiry/珍寶", "嗯！我的珍寶可多了，哪！我手上這本書可是我收藏寶物中最喜愛了。\n");
    set("inquiry/寶物", "嗯！我的珍寶可多了，哪！我手上這本書可是我收藏寶物中最喜愛了。\n");
    set("inquiry/書", "這本書可是有神秘之處的，上頭寫的【幽】字可有是大大的秘密。\n");
    set("inquiry/幽", "我看你這小夥子蠻順眼的，我就跟你說吧！\n"
                      "              你可以在戰鬥中誠心的默唸著幽(you)，可\n"
                      "              以發出驚人之威力哦！！\n",
    );
    set("chat_chance_combat",80);
    set("chat_msg_combat", ({
        (:command("you"):),
        (:command("say 你這惡賊，接我這一招，受死吧！！！"):),
    }) );

    setup();
    set_living_name("__XIE__");
    carry_object(__DIR__"wp/darksword.c")->wield();
    carry_object(__DIR__"obj/book.c");
    carry_object(__DIR__"obj/bone.c");
}

void init()
{
    ::init();
    add_action("do_guard", "go");

}

int do_guard(string arg)
{
    object me;
    object obj;
    me=this_player();
    obj=this_object();
    if( (arg!= "southwest") || !this_player()->visible(this_object()) ) return 0;
    write( name() + "將你攔了下來。\n");
    command("say 咦！？小賊！！想偷我的珍寶來著！？");
    command("say 你快走吧！下次別讓我見到你，否則！哼哼！！！");
    obj->kill_ob(me);
    return 1;
}

void die()
{
    object ob;

    if( !ob = query_temp("last_damage_from") ) ob = this_player(1);

    if( !ob ) {
        ::die();  return;
    }

    message("world:world1:vision",CYN"\n  武林傳出了一則驚人的消息:\n\n\t「幽冥惡王」天殘邪佬終於敗給了"+ob->name(1)+"。\n\n"+NOR,users());
    ob->add("popularity",3); //聲望
    ::die();
    return;
}
