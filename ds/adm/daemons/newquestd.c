/*  questd.c  ���Ⱥ��F
write by Acme- 2007.02.04
 */

#define QUEST_SIZE 40
// #pragma save_binary
#include <ansi.h>

inherit F_CLEAN_UP;
inherit F_SAVE;

mapping assigner;
mapping rewarder;

void create()
{
    seteuid(getuid());
    if( !restore() && !mapp(assigner) )
        assigner = ([]);
    if( !restore() && !mapp(rewarder) )
        rewarder = ([]);
}

string query_save_file()
{
    return DATA_DIR + "questd";
}

mapping getAssigner() { return assigner; }
mapping getRewarder() { return rewarder; }

protected string getItemFile(object item)
{
    string file;
    if( !objectp(item) ) return "";
    file = file_name(item);
 if( sscanf(file, "%s#%*d", file) != 2 )
        return "";
    return file + ".c";
}

protected void insertAssigner(string npc_file, string quest_file)
{
    if( undefinedp(assigner[npc_file]) )
        assigner[npc_file] = ({});
    
    if( member_array(quest_file, assigner[npc_file]) != -1 )
        return;
    
    assigner[npc_file] += ({ quest_file });
}

protected void insertRewarder(string npc_file, string quest_file)
{
    if( undefinedp(rewarder[npc_file]) )
        rewarder[npc_file] = ({});

    if( member_array(quest_file, rewarder[npc_file]) != -1 )
        return;

    rewarder[npc_file] += ({ quest_file });
}

void doScanQuest(string dir)
{
    string file;
    mixed *files, *dirent;

    if( !stringp(dir) ) dir = "/open/quest/";

    files = get_dir(dir, -1);

    if( !sizeof(files) ) {
        if( file_size(dir) == -2 ) write("QUESTD: ���ȥؿ��O�Ū��C (" + dir + ")\n");
        else write("QUESTD: �S���o�ӥ��ȥؿ��C (" + dir + ")\n");
        return;
    }

    // �M�šA��ӭ���
    assigner = ([]);
    rewarder = ([]);

    write("���˥��Ȥ� " + dir + " ...\n\n");

    foreach( dirent in files ) {
        file = dir + dirent[0];
        write( sprintf("%-60s", file) );

        if( !file->isQuest() ) {
            write( " -> �D������.\n");
        continue;
        }

        insertAssigner(file->getAssigner(), file);
        insertRewarder(file->getRewarder(), file);

        write(" -> OK.\n");
    }

    write("\n���˧����C\n\n");
    
    save();
}

protected void confirmAssign(string input, object player, string quest_file)
{
if( input != "" ) {
        if( input[0] == 'y' || input[0] == 'Y' ) {
        } else if( input[0] == 'n' || input[0] == 'N' ) {
            tell_object(player, HIB"(�A��󱵨����ȡG" + quest_file->getName() + ")\n"NOR);
            return;
        } else {
            tell_object(player, HIW"\n�A�n�����o�@�ӥ��ȶܡH (Y/n) "NOR);
            input_to("confirmAssign", player, quest_file);
            return;
        }
    }

    // ��������
    tell_object(player, HIY"(�A�����F���ȡG" + quest_file->getName() + ")\n"NOR);
    player->setToDo(quest_file);
    player->save();
}

protected void doAssignQuest(object npc, object player, string quest_file)
{
    int i, message_size;
    string *assignMessage;

    assignMessage = quest_file->getAssignMessage();
    message_size = sizeof(assignMessage);

    // �T����ܥi�H�Φ��@�y�@�y���A�������@���Q�X��
    for(i=0;i<message_size;i++)
        message_vision(assignMessage[i], npc, player);

    tell_object(player, HIW"\n�A�n�����o�@�ӥ��ȶܡH (Y/n) "NOR);
input_to("confirmAssign", player, quest_file);
}

// ���o�i�Ѫ�����index��
protected int* getQuestIndex(object player, string npc_file)
{
    int i;
    string quest_file;
    int *index = ({});

    quest_file = assigner[npc_file];
    for(i=0;i<sizeof(quest_file);i++) {
        // �w�g���F
if( player->getToDo(quest_file[i]) ) continue;

// �w�g�����F�ӥB���O�i���ƸѪ�����
if( player->isSolved(quest_file[i]) != -1 && !quest_file[i]->isNewly() ) continue;

        // �e�m����F��~�����|��������
        if( !quest_file[i]->preCondition(player) ) continue;

        index += ({ i });
    }

    return index;
}

protected void getSelect(string input, object player, object npc, int *index)
{
int select;
    string quest_file, npc_file;

if( !input || input == "" ) {
        tell_object(player, "�п�ܡH");
input_to("getSelect", player, npc, index);
return;
}

if( sscanf(input, "%d", select) != 1 ) {
        tell_object(player, "�п�J�Ʀr�A�п�ܡH");
input_to("getSelect", player, npc, index);
return;
}

    if( select == 0 ) return;

    if( select < 0 || select > sizeof(index) ) {
        tell_object(player, "�п�J���T���Ʀr�A�п�ܡH");
input_to("getSelect", player, npc, index);
return;
    }
    
npc_file = getItemFile(npc);
    select--;
    quest_file = assigner[npc_file][index[select]];
    
    doAssignQuest(npc, player, quest_file);
}

int doAssign(object npc, object player)
{
    int i, *index;
    string npc_file, *quest_file, msg;

    if( !objectp(npc) || !objectp(player) ) return 0;
    if( !userp(player) ) return 0;

    npc_file = getItemFile(npc);

    if( undefinedp(assigner[npc_file]) ) {
        tell_object(player, HIW + npc->name() + "���G���ӷQ�z�A�C\n"NOR);
        return 0;
    }

    if( player->getToDoListSize() >= QUEST_SIZE ) {
        tell_object(player, HIW"�A�����Ȥ�x���F�C\n"NOR);
        return 0;
    }

    quest_file = assigner[npc_file];
    index = getQuestIndex(player, npc_file);

    if( !sizeof(index) ) {
        tell_object(player, HIW + npc->name() + "��ۧA�L���ܷN�C\n"NOR);
        return 0;
    }
    
    // �u���@�ӥ��ȥi�H�Ѫ��ܡA�N���C�X�ﶵ
    if( sizeof(index) == 1 ) {
        doAssignQuest(npc, player, quest_file[index[0]]);
        return 1;
    }

    msg = "�A�ثe�i�H�V" + npc->name() + "���o�����Ȧ��G\n";
    msg += "   0. �����A������������ȡC\n";
    for(i=0;i<sizeof(index);i++)
    msg += sprintf("  %2d. %s\n", i+1, quest_file[index[i]]->getName() );
    msg += "\n�п�ܡH";
    
    tell_object(player, msg);
    input_to("getSelect", player, npc, index);

    return 1;
}

void doKilled(object npc, object player)
{
    mapping toDoList;
    string npc_file;
    string *key;
    int i, size;

    if( !objectp(npc) || !objectp(player) ) return;
if( userp(npc) || !userp(player) ) return;
    
    npc_file = getItemFile(npc);
    toDoList = player->getToDoList();
    
    if( !mapp(toDoList) ) return;
    
    key = keys(toDoList);
    size = sizeof(key);
    
    for(i=0;i<size;i++) {
        if( undefinedp(toDoList[key[i]]["killed"][npc_file]) ) continue;
        player->addKilled(key[i], npc_file, 1);
    }
}

protected int checkKill(object npc, object player, string quest_file)
{
    int i, size, *value;
string *key;
    mapping kill;
    
    kill = quest_file->getKill();
    
    if( !mapp(kill) ) return 1;
    
    // �ˬdkill
    key = keys(kill);
    value = values(kill);
    size = sizeof(key);
    
    for(i=0;i<size;i++)
        if( player->getKilled(quest_file, key[i]) < value[i] ) return 0;

    return 1;
}

protected int checkItem(object npc, object player, string quest_file)
{
int ok, amount, need_amount;
    int i, j, inv_size, size;
    int *value;
string *key, item_file;
    mapping item;
    object *inv;
    
    item = quest_file->getItem();
    
    if( !mapp(item) ) return 1;

    // �ˬditem
    key = keys(item);
    value = values(item);
    size = sizeof(key);
    
    inv = all_inventory(player);
inv_size = sizeof(inv);

// ���Ȼݭn�����~
    for(i=0;i<size;i++) {
        // �Ӫ��~�w�g�j���n�F
        if( player->getItem(quest_file, key[i]) >= value[i] ) {
            ok++;
            continue;
        }
        
        // ���⨭�W�����~
        for(j=0;j<inv_size;j++) {
            item_file = getItemFile(inv[j]);

//            write("    ���W���~�G" + inv[j]->short() + " (" + item_file + ")\n");
            // �P�@���ɦW
            if( item_file == key[i] ) {

            message_vision("$N���$n���D�G�ݨӧA�w�g�a�ӤF" + inv[j]->name() + "�C\n", npc, player);

                // �D�ƦX���~
                if( !function_exists("query_amount", inv[j]) ) {
                    destruct(inv[j]);
                    player->addItem(quest_file, key[i], 1);

                // �ƦX���~
                } else {
                
                    // ���Ȼݭn���ƶq - �w�g�������ƶq = �ٻݭn�h�֪����~
                need_amount = value[i] - player->getItem(quest_file, key[i]);
                    amount = inv[j]->query_amount();

                    // �ƶq����
                if( amount >= need_amount ) {
                        inv[j]->add_amount(-need_amount);
                        player->addItem(quest_file, key[i], need_amount);
                    // �ƶq������
                    } else {
                    destruct(inv[j]);
                        player->addItem(quest_file, key[i], amount);
                    }
                }
                
            // �g�L�@�s�ꪺ�ˬd��A�i��w�g�j���n�F
                if( player->getItem(quest_file, key[i]) >= value[i] ) {
                ok++;
                break;
                }
            }
        }
    }
   
    if( ok == size ) return 1;
    return 0;
}

protected int isReward(object npc, object player, string quest_file)
{
    int i, message_size;
    string *rewardMessage;

    if( !checkItem(npc, player, quest_file) ) return 0;
    if( !checkKill(npc, player, quest_file) ) return 0;
    if( !quest_file->postCondition(player, npc) ) return 0;
    
    // �q���Ȫ���
    player->delToDo(quest_file);
    
    // �w��
    player->setSolved(quest_file);
    player->save();
    
    // ��ܸѧ����T��
    rewardMessage = quest_file->getRewardMessage();
    message_size = sizeof(rewardMessage);

    // �T����ܥi�H�Φ��@�y�@�y���A�������@���Q�X��
    for(i=0;i<message_size;i++)
        message_vision(rewardMessage[i], npc, player);
    return 1;
}

int doReward(object npc, object player)
{
    int i, quest_size, ok=0;
    string npc_file, *quest_file;

    if( !objectp(npc) || !objectp(player) ) return 0;
    if( !userp(player) ) return 0;

    npc_file = getItemFile(npc);
  
    if( undefinedp(rewarder[npc_file]) )
        return 0;

    quest_file = rewarder[npc_file];
    quest_size = sizeof(quest_file);

    for(i=0;i<quest_size;i++) {    
        // �S�����o�ӥ���
        if( !player->getToDo(quest_file[i]) ) continue;
        
        // ���ȱ���F��~�৹��
        if( !isReward(npc, player, quest_file[i]) ) continue;
        

        // ������y
        quest_file[i]->reward(player, npc);
        
        ok = 1;
    }
    
    if( ok ) return 1;
    else return 0;
}

int hasQuest(object player, object npc)
{
    if( !sizeof( getQuestIndex(player, getItemFile(npc))) ) return 0;
    else return 1;
}
