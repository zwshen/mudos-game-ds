#include <ansi.h>
#define TREE "/u/a/acme/mud_game/ma_game/npc/obj/laurel.c"
#include <path.h>
inherit SELLMAN;
inherit NPC;
inherit F_SAVE;
string *place=({"/open/world1/tmr/area/street4.c","/open/world1/cominging/area/bnorth.c","/open/world1/acme/area/st.c"});

mapping game_record;
mapping game_no;

void check_game();
void create()
{
        restore();
        this_object()->delete("short");
        set_name(HIM"嫦娥"NOR, ({ "the goddess of the moon","goddess","moon"}));
        set("long", "他是住在月亮上頭的神仙，長得十分標緻，\n"
                    "且常常帶著笑容，在每年的中秋節，都能夠\n"
                    "見到他的蹤影哦。可以簽名(sign)領獎品。\n");
        set("level",1);
        set("gender", "女性");
        set("race", "人類");
        set("age", 20);
        set("evil",-20);
        set("attitude", "peaceful");
        set("no_fight",1);
        set("chat_chance", 50);
        set("chat_msg", ({
                (: check_game() :),
        }));
        set("sell_list",([
                "/open/world1/acme/area/npc/obj/pomelo" : 10,
                "/open/world1/acme/area/npc/obj/cake1" : 10,
                "/open/world1/acme/area/npc/obj/cake2" : 10,
                "/open/world1/acme/area/npc/obj/cake3" : 10,
                "/u/a/acme/mud_game/ma_game/npc/obj/mortar.c" : 1,
                 "/u/a/acme/mud_game/ma_game/npc/obj/pestle.c" : 1,
        ]) );
        setup();
        set_living_name("mud_game");
}
string query_save_file() { return DATA_DIR + "game/ma_game"; }

void check_game()
{
        int i;
        string month,time,day,msg="";
        object tree;

        time = ctime(time());
        month = time[4..6];
        day = time[8..9];
        switch( month )
        {
                case "Sep":     //九月
                        if( objectp(tree=find_living("ma_game")) )
                        {
                                if(!environment(tree)) destruct(tree);
                                return;
                        }
                        msg += HIM"\n\t嫦娥幽幽歎道：\n\n"NOR;
                        msg += HIG"\t\t十輪霜影轉庭梧，此夕羈人獨向隅。\n";
                        msg += "\t\t未必素娥無悵恨，玉蟾清冷桂花孤。\n\n"NOR;
                        msg+="\t(你發現天空許\多事物墜落於地面。)\n";
                        message("system",msg,users());

                        i=sizeof(place);
                        while( i-- )
                        {
                                tree=new(TREE);
                                tree->move(place[i]);
                        }
                        break;
                case "Oct":     //十月
                        if( day==" 1" )
                        {
                                if( objectp(tree=find_living("ma_game")) )
                                {
                                        if(!environment(tree)) destruct(tree);
                                        return;
                                }
                                msg += HIM"\n\t嫦娥幽幽歎道：\n\n"NOR;
                                msg += HIG"\t\t十輪霜影轉庭梧，此夕羈人獨向隅。\n";
                                msg += "\t\t未必素娥無悵恨，玉蟾清冷桂花孤。\n\n"NOR;
                                msg+="\t(你發現天空許\多事物墜落於地面。)\n";
                                message("system",msg,users());

                                i=sizeof(place);
                                while( i-- )
                                {
                                        tree=new(TREE);
                                        tree->move(place[i]);
                                }
                        }
                        else if( !this_object()->query_temp("sign") )
                        {
                                msg += HIM"\n\t嫦娥幽幽歎道：\n\n"NOR;
                                msg += HIG"\t\t中秋活動結束，請於四日內領取獎品。\n\n"NOR;
                                message("system",msg,users());
                                this_object()->set_temp("sign",1);
                        }
                        break;
        }
        return;
}

void init()
{
        add_action("do_sign","sign");
        add_action("do_list","list");
        add_action("do_buy","buy");
        {
                object ob;
                ::init();
                if( interactive(ob = this_player()) && !is_fighting() )
                {
                        remove_call_out("greeting");
                        call_out("greeting", 1, ob);
                }
        }
}

void greeting(object ob)
{
        string msg="";
        if( !ob || environment(ob) != environment() ) return;
        msg = "這位"+ RANK_D->query_respect(ob) +"來買";
        if( random(2)>0 ) msg += "些月餅吃吃吧。";
        else msg+="顆柚子吃吃吧。";
        command("say "+ msg );
        return;
}

int do_sign()
{
        string id;
        object me=this_player(),gift;
        id=getuid(me);
        if( !this_object()->query_temp("sign") )
                return notify_fail("似乎時間還沒到，無法領取獎品。\n");
        if( !mapp(game_record) )
                return notify_fail("目前還無法領取獎品！\n");

        if( !undefinedp(game_no[id]) )          //有得名
        {
                write("No."+game_no[id]+"\n");
                switch( game_no[id] )
                {
                        case 1: gift=new("/u/a/acme/mud_game/gift/lv5.c"); break;
                        case 2: gift=new("/u/a/acme/mud_game/gift/lv4.c"); break;
                        case 3: gift=new("/u/a/acme/mud_game/gift/lv3.c"); break;
                        case 4: gift=new("/u/a/acme/mud_game/gift/lv2.c"); break;
                        case 5: gift=new("/u/a/acme/mud_game/gift/lv1.c"); break;
                        default: return notify_fail("你的名次似乎有問題，沒辦法領獎，請找巫師處理！\n"); break;
                }
                if( gift->move(me) )
                        message_vision("$N向$n領了一個"+gift->query("name")+"。\n",me,this_object());
                else
                {
                        gift->move(environment(me));
                        message_vision("$N向$n領了一個"+gift->query("name")+"，但掉在地上了。\n",me,this_object());
                }
                map_delete(game_no,id);
                this_object()->save();
        }

        if( !undefinedp(game_record[id]) )      //有參加
        {
                gift=new("/u/a/acme/mud_game/gift/pill.c");
                gift->set("add_exp",to_int(100000/game_record[id]));
                if( gift->move(me) )
                        message_vision("$N向$n領了一個"+gift->query("name")+"。\n",me,this_object());
                else
                {
                        gift->move(environment(me));
                        message_vision("$N向$n領了一個"+gift->query("name")+"，但掉在地上了。\n",me,this_object());
                }
                map_delete(game_record,id);
                this_object()->delete_temp("sign");
                this_object()->save();
                return 1;
        }
        else return notify_fail("你沒辦法領取獎品！\n");
        return 1;
}

