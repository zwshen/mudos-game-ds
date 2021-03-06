#include <path.h>
#include <ansi.h>
inherit ITEM;
inherit F_AUTOLOAD;
inherit F_SAVE;
void create()
{
        object me;
        me=this_player();
        set_name(HIR"封魔盒"NOR,({"beastbox"}));
        set_weight(300);
        if( clonep() )
                set_default_object(__FILE__);
        else {
                set("long", @LONG
這是一件專放魔獸的盒子。
<放出魔獸(pput 魔獸的id)>
<拿出魔獸(pget 寵物的id)>
LONG);
                set("unit", "件");
                set("no_sell",1);
                set("no_drop",1);
                set("value",50000);
                set("amount",1);
        }
}
int query_autoload() { return 1; }
void init()
{
        add_action("do_get","pget");
        add_action("do_home","pput");
}
int do_get(string arg)
{
        object npc,pet;
        object me;
        int lv,bage;
        if(!this_player())
                return 0;
        me=this_player();
        npc=present("beastbox",me);
        bage=me->query("beast_age",1);
        if(!npc)
                return 1;
        if(environment(me)->query("no_cast")||environment(me)->query("no_kill"))
                return notify_fail("請勿在這拿出魔獸\n");
        if(me->query("diebeast"))
                return notify_fail(HIW"你的魔獸已經死了\n"NOR);
        if(me->query_temp("pet")>0)
                return notify_fail(HIW"一次只能一隻寵物或魔獸保護你\n"NOR);
        if(me->query("mud_age")-bage<30)
                return notify_fail(HIW"你必需等一下才能在拿出魔獸\n");
        if(arg==me->query("bname"))
        {
                if(me->query("bname")=="wind")
                        pet = new("/u/p/promise/pet/beast-w");
                else if(me->query("bname")=="blood")
                        pet = new("/u/p/promise/pet/beast-b");
                else if(me->query("bname")=="ice")
                        pet = new("/u/p/promise/pet/beast-i");
                else return notify_fail("目前能拿的只有wind ice blood三種魔獸\n");
                me->delete("beast_age");
                if(!me->query("beast_age"))
                        me->set("beast_age",me->query("mud_age"));
                pet->set("owner",me->query("id"));
                pet->set_temp("owner",me->query("id"));
                pet->restore();
                pet->set("pet",1);
                if(pet->query("hp")<1)
                        pet->set("hp",1);
                pet->set_temp("pet",1);
                pet->set_leader(me->query("id"));
                pet->invocation(me);
                pet->set("actions",(: call_other, "/adm/daemons/race/beast.c", "query_action" :));
                pet->move(environment(me));
                lv=pet->query("level");
                pet->set_name(pet->query("name"),({me->query("id")+" "+me->query("bname")+" beast","beast"}));
                pet->set("dex",lv*2);
                pet->set("str",lv*2);
                pet->set("con",lv*2);
                pet->set("lck",lv*2);
                pet->set("air",lv*2);
                pet->set("int",lv*2);
                pet->set("wis",lv*2);
                pet->set("mus",lv*2);
                pet->set("max_hp",pet->query("con")*400);
                pet->set("max_mp",pet->query("int")*30);
                pet->set("max_ap",pet->query("mus")*40);
                pet->set("max_force",pet->query("air")*40);
                if(me->query("bname")=="blood")
                {
                        pet->set_temp("apply/damage",pet->query("level")*6);
                        pet->set_temp("apply/hit",pet->query("level")*6);
                        pet->set_temp("apply/armor",pet->query("level"));
                }
                if(me->query("bname")=="wind")
                {
                        pet->set_temp("apply/damage",pet->query("level")*1);
                        pet->set_temp("apply/hit",pet->query("level")*6);
                        pet->set_temp("apply/armor",pet->query("level")*3);
                }
                if(me->query("bname")=="ice")
                {
                        pet->set_temp("apply/damage",pet->query("level")*3);
                        pet->set_temp("apply/hit",pet->query("level")*6);
                        pet->set_temp("apply/armor",pet->query("level")*2);
                }
                if(pet->query("force")>pet->query("max_force"))
                        pet->set("force",pet->query("max_force"));
                if(pet->query("ap")>pet->query("max_ap"))
                        pet->set("ap",pet->query("max_ap"));
                pet->set("title",me->query("name")+"的");
                me->set_temp("pet",1);
                me->set_temp("bname",me->query("bname")+" beast");
                message_vision(HIC+me->query("name")+"由封魔盒內拿出一隻"
                       +pet->query("name")+HIC"\n"+pet->query("name")
                        +HIC"來到"+me->query("name")+"的腳邊\n"NOR,me);
        }
        else return notify_fail(HIG
                "\t若你養的是風魔獸請打pget wind..\n"+
                "\t若是血魔獸請打pget blood..\n"+
                "\t冰魔獸的話是打pget ice\n"NOR);
        return 1;
}
int do_home(string argx)
{
        object npc;
        object me;
        if(!this_player())
        return 0;
        me=this_player();
        if(argx==me->query("bname"))
        {
                if(!me->query("name")||!me)   return 0;
                npc=present(me->query("id")+" "+me->query("bname")+" beast",environment(me));
                if(!npc)
                        return notify_fail(HIW"這邊沒這隻mob\n"NOR);
                if(npc->query("owner")!=me->query("id"))
                        return notify_fail(HIW"這隻魔獸不是你的\n");
                message_vision(HIC+me->query("name")+"將身邊的"+
                npc->query("name")+HIC"回封魔盒中\n"NOR,me);
                npc->save();
                destruct(npc);
                me->delete_temp("pet");
                me->delete_temp("bname");
        }
        else printf(HIC"你有養過這隻魔獸嗎...??\n"NOR);
        return 1;
}

