// 2001.8.19 Com@DS 修改
#define DROP_CMD "/cmds/std/drop"
#include <ansi.h>
inherit F_DBASE;
inherit F_CLEAN_UP;

void create() 
{
        seteuid(getuid());
        set("channel_id", "離線精靈(Kickout)");
}

int main(object me, string arg)
{
        int i;
        object ob, *team, ride;
          object *inv;
                        
        if( !arg ) return notify_fail("指令格性: kickout <id>\n");       
        ob = find_player(arg); //present(arg, environment(me));
        if( !ob ) return notify_fail("沒有這個人\n");
        if(  wiz_level(me) <= wiz_level(ob) ) 
                 return notify_fail("你沒有這個權力。\n");
// add ++
        if(team=ob->query_team())
        {
                if(arrayp(team) && sizeof(team)>1 )
                {
                        for(i=0;i<sizeof(team);i++)
                        {
                                tell_object(team[i],HIW"【隊伍】"+ob->name(1)+"離開了這個隊伍。\n"+NOR);
                                ob->dismiss_team();
                        }
                }
        }

        if( !wizardp(ob) ) {
                inv = all_inventory(ob);
                for(i=0; i<sizeof(inv); i++)
                {
                        if( inv[i]->query("secured") ) inv[i]->delete("secured");
                        if( inv[i]->query("base_value") ) continue;
                        if( inv[i]->query_autoload()  ) continue;
                        if( inv[i]->query("equipped")) inv[i]->unequip();
                        DROP_CMD->do_drop(ob, inv[i]);
                }
        }
// add --

        CHANNEL_D->do_channel(this_object(), "sys",
                me->name()+"("+"把"+")"+ob->name() + "(" + ob->query("id") + ")踢出了遊戲。");
        CHANNEL_D->do_channel(this_object(), "rumor",
                ob->name() +"("+ob->query("id")+")"+ "被系統踢出了遊戲。");

// add ++
        if(ride=ob->query_temp("ride"))
        {
                message_vision("$N從"+ride->name()+"上跳了下來。\n", ob);
                ride->delete_temp("riden");
                ride->move(environment(ob));
                ob->delete_temp("ride");
        }
        ob->remove_all_killer();
        ob->remove_all_enemy();

        ROOM_D->moveout(environment(ob),ob); //add by luky
// add --
        ob->save();
        destruct(ob);
        return 1;
}


