// mailbox.c
#include <ansi.h>

inherit ITEM;
inherit F_SAVE;

mapping *mails;

void get_mail_text(mapping mail, string str);

void create()
{
        set_name("夢幻信箱", ({ "mailbox" }) );
        set("long",@LONG

                你可以用以下指令來處理你的郵件
                
                mail <某人>               寄信給別人。
                forward <信件編號> <某人> 將某封信轉寄給別人。
                from                      查看信箱中的信件。
                read <信件編號>           閱\讀一封信件。
                discard <信件編號>        丟棄一封信件。

LONG
        );
        set("unit", "個");
        set("no_drop", 1);
//      set_temp("invis");
        setup();
}

int set_owner(string id)
{
        set("owner_id", id);
        return restore();
}

void init()
{
        if( this_player() && environment()==this_player() )
        {
                set_owner( (string)this_player()->query("id") );
                this_player()->delete("new_mail");
                this_player()->set_temp("mbox_ob", this_object());
                add_action("do_mail", "mail");
                add_action("do_forward", "forward");
                add_action("do_from", "from");
                add_action("do_read", "read");
                add_action("do_discard", "discard");
        }
}

string query_save_file()
{
        string id;

        if( !stringp(id = query("owner_id")) ) return 0;

        return DATA_DIR + "mail/" + id[0..0] + "/" + id;
}

void receive_mail(mapping mail)
{
        if( !pointerp(mails) ) mails = ({ mail });
        else mails += ({ mail });
        save();
}

void send_mail(string receiver, mapping mail)
{
        object ppl, mbx;

        // Get the mailbox or make a new one if not found.
        ppl = find_player(receiver);
        if( !mbx ) {
                mbx = new(MAILBOX_OB);
                mbx->set_owner(receiver);
        }

        // Receive the mail and destruct the objects if receiver is off-line.
        mbx->receive_mail(mail);
        if(ppl){
                mbx = ppl->query_temp("mbox_ob");
                write ("已通知 " + receiver + " 收信!\n");
                tell_object(ppl, HIC"\n有您的新信﹗\n\n"NOR);
        }
        else MAIL_D->send_mail(receiver);

        destruct(mbx);
}

int do_mail(string arg)
{
        mapping mail;

        if( this_player()!=environment() ) return 0;

        if( !arg || arg=="" )
                return notify_fail("你要寄信給誰﹖\n");

        mail = ([
                "from": this_player()->name(1) + "(" + this_player()->query("id") + ")",
                "title": "無題",
                "to": arg,
                "time": time(),
                "text": ""
        ]);
        write("信件標題﹕");
        input_to("get_mail_title", mail);
        return 1;
}

void get_mail_title(string str, mapping mail)
{
        if( str!="" ) mail["title"] = str;
        write("信件內容﹕\n");
        this_player()->edit( (: get_mail_text, mail :) );
}

void get_mail_text(mapping mail, string str)
{
        mail["text"] = str;
        write("您自己要留一份備份嗎(y/n)﹖[n]");
        input_to("confirm_copy", mail);
}

void confirm_copy(string yn, mapping mail)
{
        if( yn[0]=='y' || yn[0]=='Y' ) receive_mail(mail);
        send_mail(mail["to"], mail);
        write ("請問還有要寄給誰嗎(y/n) ? [n]");
        input_to ("confirm_other", mail);
}

void get_id (string str, mapping mail)
{
        if( str!="" ) mail["to"] = str;
        send_mail(str, mail);
        write ("請問還有要寄給誰嗎(y/n) ? [n]");
        input_to ("confirm_other", mail);
}

void confirm_other(string yn, mapping mail)
{
        if ( yn[0]=='y' || yn[0]=='Y' ) {
          write ("請一次一個輸入名單, 結束請用句點 '.'  : ");
          input_to("mail_other", mail);
        }
}

void mail_other(string name, mapping mail)
{
        if (name == ".")
          write ("信寄出去了.\n");
        else {
          mail["to"] = name;
          send_mail(name, mail);
          write ("請一次一個輸入名單, 結束請用句點 '.'  : ");
          input_to("mail_other", mail);
        }
}

int do_from()
{
        int i;

        if( !pointerp(mails) || !sizeof(mails) ) {
                write("你的信箱中目前沒有任何信件。\n");
                return 1;
        }
        write("你的信箱中現在共有 " + sizeof(mails) + " 封信件﹕\n\n");
        for(i=0; i<sizeof(mails); i++)
                printf("%2d %-40s 寄信人﹕%-25s\n",
                        i+1, mails[i]["title"], mails[i]["from"] );
        write("\n");
        return 1;
}

int do_read(string arg)
{
        int num;

        if( !arg || !sscanf(arg, "%d", num) )
                return notify_fail("你要讀哪一封信﹖\n");

        if( !pointerp(mails) || num < 1 || num > sizeof(mails) )
                return notify_fail("沒有這個編號的信件。\n");

        num --;

        printf("信件標題﹕%s\n寄 信 人﹕%s\n\n%s\n",
                mails[num]["title"], mails[num]["from"], mails[num]["text"] );

        return 1;
}

int do_discard(string arg)
{
        int num;

        if( !arg || !sscanf(arg, "%d", num) )
                return notify_fail("你要丟棄哪一封信﹖\n");

        if( !pointerp(mails) || num > sizeof(mails) )
                return notify_fail("沒有這個編號的信件。\n");

        num --;

        mails = mails[0..num-1] + mails[num+1..sizeof(mails)-1];
        save();
        write("Ok.\n");

        return 1;
}

int do_forward(string arg)
{
        string dest;
        int num;
        mapping m;

        if( !arg || sscanf(arg, "%d %s", num, dest)!=2 )
                return notify_fail("你要將哪一封信轉寄給別人﹖\n");

        if( !pointerp(mails) || num > sizeof(mails) )
                return notify_fail("沒有這個編號的信件。\n");

        num --;

        m = ([]);
        m["title"] = mails[num]["title"];
        m["text"] = mails[num]["text"];
        m["time"] = mails[num]["time"];
        m["from"] = mails[num]["from"] + "/轉寄自" + this_player()->query("name");
        m["to"] = dest;
        send_mail( dest, m );
        write("Ok.\n");

        return 1;
}

void owner_is_killed() { destruct(this_object()); }
