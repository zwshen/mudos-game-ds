#include <ansi2.h>
inherit ITEM;
inherit F_UNIQUE;

string *obj = ({ });
void restore_box_autoload();
void save();
void restore_box_autoload();
void remove() { save(); }

void create()
{
        set_name(BBLU+HIC"夢幻寶盒"NOR, ({ "dream box", "box" }));
        set("long", @LONG
一個迷幻似的寶盒, 外表裝飾並不怎麼的華麗, 但是卻閃出刺眼的
光芒, 也許是上面所鑲嵌的寶石, 也可能是寶盒上方的那一顆珍珠
, 整個寶盒容量看起來不大, 但裡面卻藏著許多秘密.
LONG
        );
        set("value", 21300);
        set("no_give", 1);
        set("no_sell", 1);
        set("no_drop", 1);
        set("unit", "個");
        set_max_encumbrance(9999999);
        setup();
        restore_box_autoload();
}

void init()
{
        add_action("do_save_o", "sa");
        add_action("do_restore_o", "re");
}

int do_save_o()
{
        save();
        return save_object(__DIR__"dream_box.o", 1);
}

int do_restore_o()
{
        return restore_object(__DIR__"dream_box.o", 1);
}

void save()
{
        object *inv;
        int i, j;
        mixed param;

        inv = all_inventory();
        obj = allocate(sizeof(inv));
        for(i=0, j=0; i<sizeof(inv); i++) {
                if( inv[i]->query_unique() ) continue;
                obj[j] = base_name(inv[i]);
                j++;
        }
        obj = obj[0..j-1];
}

void restore_box_autoload()
{
        int i;
        object ob;
        string file, err;

        restore_object(__DIR__"dream_box.o");

        for(i=0; i<sizeof(obj); i++) {
                file = obj[i];
                err = catch(ob = new(file));
                if( err || !ob ) {
                        write("你覺得似乎失落了什麼重要的東西﹐最好通知一下巫師。\n");
                        write_file(__DIR__"AUTOLOAD", sprintf("Fail to autoload %s of %s, error %s\n",
                                file, this_object()->query("name"), err));
                        continue;
                }
                export_uid(ob);
                ob->move(this_object());
//              if(ob) ob->autoload(param);
        }
}

int query_autoload() { return 1; }
