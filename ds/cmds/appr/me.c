// /cmds/wiz/me.c
//
// Kenny@Broken.History (6/18/1996)

inherit F_CLEAN_UP;
inherit "/feature/vi";                           // 繼承編輯功能

int file_exists(string file);

int main(object me, string arg)
{
        string file, oldfile;
        object ob;

        if (in_edit(me)) return notify_fail("你已經在使用編輯器了。\n");
        if (!arg) return notify_fail("指令格式：me <檔名>|<物件名>\n");

        seteuid(geteuid(me));
        file = resolve_path(me->query("cwd"), arg); // 取得檔名
        if (!file_exists(file)) // check virtual object
        {
                string *path=explode(file, "/");
                oldfile = file;
                file = "/"+implode(path[0..<2], "/")+"/_"+path[<1];
        }
        if (!file_exists(file))
        {       // 新檔
                ob = present(arg, me);  // 檢查身上的物件
                if (!ob) ob = present(arg, environment(me)); // 檢查房間里的物件
                if (ob && me->visible(ob))
                        file = base_name(ob) + ".c"; // 取得物件的檔名
                else    file = oldfile;
        }

        start_edit(file);               // 呼叫編輯器，開始編輯
        return 1;
} // main()

int file_exists(string file)
{
        if (!stringp(file) || file=="") return 0;
        return file_size(file)>=0;
}

int  help(object me)
{
        write(@HELP
指令格式：me <檔名>|<物件名>

利用此一指令可直接在線上編輯檔案，詳細說明請看編輯器內的線上輔助說明。

相關指令：edit、update。
HELP
                );
        return 1;
} // help()
