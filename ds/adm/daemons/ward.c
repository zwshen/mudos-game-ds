/* ward.c �Ԫ����F
   created by Acme 2007.08.02
*/

// update by tmr 2008/02/11

// #pragma save_binary

#include <ansi.h>

inherit F_SAVE;

string *start;
mapping controller;

void create()
{
    seteuid(getuid());

    if( !restore() && mapp(controller) ) {
        controller = ([]);
    }

    start = ({});

    // ���}�߸�
    set_heart_beat(1);
}

string query_save_file()
{
    return DATA_DIR + "ward";
}

private void doSetWar(string war_file)
{
    if( !undefinedp(controller[war_file]) )
        return;

    controller[war_file] = ([]);
    controller[war_file]["start"] = 0;
    controller[war_file]["cnt"] = random(20);
}

void doScanWar(string dir)
{
    string file;
    mixed *files, *dirent;

    if( !stringp(dir) ) dir = "/world/war/";

    files = get_dir(dir, -1);

    if( !sizeof(files) ) {
        if( file_size(dir) == -2 ) write("QUESTD: �Ԫ��ؿ��O�Ū��C (" + dir + ")\n");
        else write("QUESTD: �S���o�ӾԪ��ؿ��C (" + dir + ")\n");
        return;
    }

    // �M�šA��ӭ���
    controller = ([]);

    write("���˾Ԫ��� " + dir + " ...\n\n");

    foreach( dirent in files ) {
        file = dir + dirent[0];
        write( sprintf("%-60s", file) );

        if( !file->isWar() ) {
            write( " -> �D�Ԫ���.\n");
            continue;
        }

        doSetWar(file);
        write(" -> OK.\n");
    }

    write("\n���˧����C\n\n");
    
    save();
}

// �P�_�԰��O�_���b�@�Τ�
int isActive(string war_file) {
    if( undefinedp(controller[war_file]) ) return 1;
    if( member_array(war_file, start) != -1 ) return 1;
    if( controller[war_file]["start"] != 0 ) return 1;

        return 0;       
}

// �}�l�Ԫ�
int doStartWar(object ppl, string war_file)
{
        if( isActive(war_file) == 1 ) return 0;
    if( war_file->doStartWar(ppl) == 0 ) return 0;

    start += ({ war_file });
    controller[war_file]["start"] = time();
    controller[war_file]["duration"] = war_file->getDuration();

    return 1;
}

// �����Ԫ�
int doEndWar(string war_file)
{
    if( undefinedp(controller[war_file]) ) return 0;
    if( controller[war_file]["start"] == 0 ) return 0;
    if( war_file->doEndWar() == 0 ) return 0;

    start -= ({ war_file });
    controller[war_file]["start"] = 0;

    return 1;
}

// �C���߸��N�ˬd�ثe�Ҧ��}�Ҫ��Ԫ����A�O�_�w�g���Ԫ��ɶ���
void heart_beat()
{
    int i, size;
    string war_file;

    size = sizeof(start);

    for(i=0; i<size; i++) {
        war_file = start[i];

        if( undefinedp(controller[war_file]) ) continue;
        if( controller[war_file]["start"] == 0 ) continue;

        // �ˬd�O�_�ɶ���
        if( controller[war_file]["duration"] != 0 ) {
            int nowTime = time();
            int startTime = controller[war_file]["start"];
            int duration = controller[war_file]["duration"];

            if( nowTime - startTime >= duration ) {
                doEndWar(war_file);
            }
        }

        // ���C�ӾԪ����߸����}���P�ɾ��B�z
        if( controller[war_file]["cnt"] > 0 ) {
            controller[war_file]["cnt"]--;
            continue;
        }

        controller[war_file]["cnt"] = random(20);

        // ����Ԫ����߸�
        war_file->doHeartBeat();
    }
}

mapping getController()
{
    return controller;

}

string* getStart()
{
    return start;
}



