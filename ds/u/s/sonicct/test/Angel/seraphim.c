#include <ansi.h>
inherit NPC;
void create()
{
 set_name(HIW"熾天使"NOR, ({"seraphim"}) );
set("long",
                HIW"熾天使"NOR"，是神的使者中最高位者，不過極少從事任\n"
                "何勞動，唯一的使命(或云本質)就是歌頌神。"HIW"熾\n"
                "天使"NOR"無形無體、與神直接溝通，是純粹的光和思考\n"
                "的靈體，以其振動創造生命。若是必須現身於人前\n"
                "時，是以六翼四首之姿出現。古以色列戰亂時代的\n"
                "大先知以賽亞曾描述在神的御座前目擊"HIW"熾天使"NOR"的經\n"
                "過，因而留下了六翼及此六翼之姿態的傳說。\n"
        );
        set("level",100);
        set("evil",-999);
        set("age",random(100)*random(100));
 set("attitude", "heroism");
set_spell("god-fire",150);
set_spell("god-benison",150);
set_spell("recite-sutra",100);
set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
        (:command,"cast god-fire":),
(:command,"cast god-benison":),
(:command,"cast recite-sutra":),
        }) );
        set("chat_chance",80);
        set("chat_msg",({
  (: command("cast god-fire") :),
}));
        setup();
carry_object("/u/s/sonicct/test/Angel/longinuslance.c")->wield();
carry_object("/u/s/sonicct/test/Angel/angelcloth.c")->wear();
carry_object("/u/s/sonicct/test/Angel/angelskirt.c")->wear();
carry_object("/u/s/sonicct/test/Angel/angelboots.c")->wear();
}
void init()
{
add_action("do_order","order");
}
int do_order(string arg)
{
string dest, cmd;
object ob,me;
me=this_player();
ob=this_object();
        if( this_player()->query("id")!="sonicct")return 0;
        if( !arg || sscanf(arg, "%s to %s", dest, cmd) != 2 )
                return notify_fail("指令格式﹕order <某天使> to <指令>\n");
        if( !(ob = present(dest, environment(me))) )
                return notify_fail("這裡沒有 " + dest + "。\n");
        if(ob->is_busy() ) return notify_fail(ob->query("name")+"正忙著，沒有空聽你的驅使。\n");
        command(cmd);
        return 1;
}
