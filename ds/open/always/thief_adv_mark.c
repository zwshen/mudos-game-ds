// 現代公會職業信物 (小偷公會-Thief)
// 編寫者: Luky 1999.9.5
//
// 進階用-Tmr
#include <weapon.h>
#include <ansi.h>
#define THIEF_D "/daemon/thief_adv.c"
inherit DAGGER;

void create()
{
        set_name("盜賊的極致",({"advanced thief dagger","dagger","ADVANCED_THIEF_MARK"}));
        set_weight(1000);
        set("long",@LONG
這是一把象徵盜賊的匕首，匕首是以不鏽鋼打造相當堅固耐用。
你可以用(help advanced thief)查看小偷進公會可用的指令。
LONG
);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("material", "iron");
                set("unit", "把");
                set("value",0);
                set("no_sell",1);
                set("no_drop",1);
                set("limit_con",1);
                set("limit_str",1);
                set("limit_int",1);
                set("limit_dex",1);
                set("backstab_bonus",15); //百分比
        }
        set("no_get",1);
        init_dagger(7);
        setup();
}

void init()
{
//        if(this_player()!=environment(this_object())) return;
//        add_action("do_help","help");
       if(wizardp(this_player())) add_action("do_backstab","stillhunt");

}

int do_help(string arg)
{
        return THIEF_D->do_help(this_player(),arg);
}

int query_autoload() { return 1; }
string query_guild() { return "thief"; }

int do_backstab(string arg)
{
        return THIEF_D->do_backstab(this_player(),arg);
}

