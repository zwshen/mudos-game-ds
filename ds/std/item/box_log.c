
/*
**********************************************************
***********       BOX 私用繼承檔 BOX_LOG       ***********
**********************************************************

Cominging@DS 2001.8.29
我更動的地方 <globals.h>
#define BOX_LOG                 "/std/item/box_log" // add by Cominging

範例模型
  mapping get = ([ "cominging" : ({ "ctime(time()) 人物 物品" }), ]);

For DS Clan: 一個 box with ACCESS_LOG 15 萬
                           BOX_LOG    20 萬

**********************************************************
***********       BOX 私用繼承檔 BOX_LOG       ***********
**********************************************************
*/

#include <ansi.h>
#define HELP "指令格式: \n       ** checkuse 'id' {-w|-l|-m}\n    -w <id> 指定查看特定玩家的紀錄\n    -l      觀看所有的紀錄, 順暢是先 get 再 put。\n    -m <get/put> 觀查 get 或 put 的紀錄。\n       ** cleanup 'id' {get|put|all}\n    get     清除 get 的紀錄。\n    put     清除 put 的紀錄。\n    all     清除所有紀錄。\n\n注意: 要用 ' ' 括起來。\n"

mapping get = ([  ]);
mapping put = ([  ]);
string op_all(string arg); // output 輸出特定 log string

void init()
{
        if( !this_object()->query("club_id") || !this_object()->query("demand_level") )
        {
                write(this_object()->name(1)+"設定錯誤, 請通知巫師。\n");
                return;
        }
        add_action("do_check", "checkuse");
        add_action("do_cleanup", "clean_record");
}

void log_put(object me, object ob)
{
        if( !arrayp(put[getuid(me)]) )
                put[getuid(me)] = ({ ctime(time()) + " " + me->name(1) + "(" + getuid(me) +") " + ob->name(1) });
        else put[getuid(me)] += ({ ctime(time()) + " " + me->name(1) + "(" + getuid(me) +") " + ob->name(1) });
        this_object()->save();
}

void log_get(object me, object ob)
{
        if( !arrayp(get[getuid(me)]) )
                get[getuid(me)] = ({ ctime(time()) + " " + me->name(1) + "(" + getuid(me) +") " + ob->name(1) });
        else get[getuid(me)] += ({ ctime(time()) + " " + me->name(1) + "(" + getuid(me) +") " + ob->name(1) });
        this_object()->save();
}

int do_check(string arg)
{
        object me, oTarget;
        string flag, chos, *logz, str, pTarget;
        // flag, chos 是用於 sscanf 辨別需求
        // logz 是在當成 put, get 需求的暫存變數
        // str 是要輸出的文字行
        // keyz 是當 put, get 的 keys()
        me = this_player();

        if( !arg ) return notify_fail(HELP);
        if( (int)CLUB_D->check_member(this_object()->query("club_id"), getuid(this_player())) < this_object()->query("demand_level") )
                return notify_fail("你無法使用。\n");
        if( sscanf(arg, "'%s' %s %s", pTarget, flag, chos) == 3 )
        {
                write(pTarget+"\n");
                if( !objectp(oTarget=present(pTarget, environment(me))) )
                        return notify_fail("沒有這個物件。\n");
                if( oTarget != this_object() && !oTarget->is_inherit_box_log() )
                        return notify_fail(HELP);
                switch(flag)
                {
                        case "-w":
                                str = HIY" ─════════ "HIG + chos + " 的 get 紀錄 "HIY"════════─\n"NOR;
                                if( arrayp(logz=get[chos]) )
                                 foreach(string tmp in logz)
                                  str += tmp +"\n";
                                else str += " ** 無紀錄 **\n";

                                str += HIY" ─════════ "HIG + chos + " 的 put 紀錄 "HIY"════════─\n"NOR;
                                if( arrayp(logz=put[chos]) )
                                 foreach(string tmp in logz)
                                  str += tmp +"\n";
                                else str += " ** 無紀錄 **\n";

                                break;
                        case "-m":
                                if( chos == "get" )
                                  str = op_all("get");
                                else if( chos == "put" )
                                  str = op_all("put");
                                else
                                  return notify_fail("選項錯誤, 可選的有 <get> <put>. \n");
                                break;
                        default:
                                return notify_fail(HELP);
                }
        }
        else if( sscanf(arg, "'%s' -l", pTarget)== 1 )
        {
                if( !objectp(oTarget=present(pTarget, environment(me))) )
                        return notify_fail("沒有這個物品喔。\n");
                if( oTarget != this_object() && !oTarget->is_inherit_box_log() )
                        return notify_fail(HELP);
                str = op_all("get") + op_all("put");
        }
        else return notify_fail(HELP);
        me->start_more(str);
        return 1;
}

int do_cleanup(string arg)
{
        object oTarget;
        string pTarget;

        if( !arg ) return notify_fail(HELP);

        if( sscanf(arg, "'%s' %s", pTarget, arg) != 2 )
                return notify_fail(HELP);
        if( !objectp(oTarget=present(pTarget, environment(this_player()))) )
                return notify_fail("沒有這個物品喔。\n");
        if( oTarget != this_object() && !oTarget->is_inherit_box_log() )
                return notify_fail(HELP);
        if( (int)CLUB_D->check_member(this_object()->query("club_id"), getuid(this_player())) < this_object()->query("demand_level") )
                return notify_fail("你無法使用。\n");
        switch(arg)
        {
                case "all":
                        get = ([ ]);
                        put = ([ ]);
                        write("清除成功\。\n");
                        message_vision("$N清除$n所有紀錄(log)。\n", this_player(), this_object());
                        break;
                case "get":
                        get = ([ ]);
                        write("清除成功\。\n");
                        message_vision("$N清除$n的 get 紀錄。\n", this_player(), this_object());
                        break;
                case "put":
                        put = ([ ]);
                        write("清除成功\。\n");
                        message_vision("$N清除$n的 put 紀錄。\n", this_player(), this_object());
                        break;
                default:
                        return notify_fail(HELP);
        }
        this_object()->save();
        return 1;
}

string op_all(string arg)
{
        string str, *keyz;

        if( arg == "get" )
        {
         str = HIY" ─════════ "HIG + this_object()->name(1) + "的 get 紀錄 "HIY"════════─\n"NOR;
         if( mapp(get) && sizeof(keyz=keys(get)) > 0 )
          for(int i=0;i<sizeof(keyz);i++)
           if( sizeof(get[keyz[i]]) > 0 )
            foreach(string tmp in get[keyz[i]])
             str += tmp + "\n";
           else continue;
         else str += " ** 無紀錄 **\n";
        }
        else if( arg == "put" )
        {
         str = HIY" ─════════ "HIG + this_object()->name(1)+ "的 put 紀錄 "HIY"════════─\n"NOR;
         if( mapp(put) && sizeof(keyz=keys(put)) > 0 )
          for(int i=0;i<sizeof(keyz);i++)
           if( sizeof(put[keyz[i]]) > 0 )
            foreach(string tmp in put[keyz[i]])
             str += tmp + "\n";
           else continue;
         else str += " ** 無紀錄 **\n";
        }
        else HIR"BOX_LOG 錯誤, 請用 report 回報 bug。\n";
        return str+"\n";
}

int is_inherit_box_log() { return 1; }
