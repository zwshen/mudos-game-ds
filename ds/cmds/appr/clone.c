// clone.c

#include "/doc/help.h"

inherit F_CLEAN_UP;

int main(object me, string file)
{
        object obj;
        string err, msg;

        seteuid( geteuid(me) );

        if (!file) file = me->query("cwf");
        if (!file)
                return notify_fail("你要複製什麼物件﹖\n");

        file = resolve_path(me->query("cwd"), file);
        if( sscanf(file, "%*s.c") != 1 ) file += ".c";
        me->set("cwf", file);

        if( file_size(file) < 0 )
                return notify_fail("沒有這個檔案(" + file + ")。\n");

        if( !find_object(file) ) {
                err = catch(call_other(file, "???"));
                if (err) {
                        write("載入失敗﹕" + err + "\n");
                        return 1;
                }
        }

        err = catch(obj = new(file));
        if (err) {
                write("複製失敗﹕" + err + "\n");
                return 1;
        }

        if( !stringp(msg = me->query("env/msg_clone")) )
                msg = "只見$N伸手凌空一指﹐變出了$n。\n";

        if( !obj->is_character() && !obj->is_house() && obj->move(me) ) {
                write(obj->query("name") + "複製成功\﹐放在你的物品欄。\n");
        message_vision(msg + "\n", me, obj);
                return 1;
        }
        if( wiz_level(me)<4 && obj->is_character() ) // 不清楚用意，改成 open can't clone only.. 注意 random 跑的招術..
        {
                if( sscanf(base_name(environment(me)),"/open/%*s") == 1 )
                {
                        write("你不能在開放區域放置怪物。\n");
                        destruct(obj);
                        return 1;
                }
        
        }

        if( obj->move(environment(me)) ) {
                write(obj->query("name") + "複製成功\﹐放在這個房間。\n");
                message_vision(msg + "\n", me, obj);
                return 1;
        }

        destruct(obj);
        return notify_fail("無法複製不能移動的物件(" + file + ")。\n");
}

int help(object me)
{
  write(@HELP
指令格式 : clone <檔名>

利用此指令可複製任何能移動之物件(含怪物)。
HELP
    );
    return 1;
}

