// help.c
#include <ansi2.h>

#include "/doc/help.h"
#define ROOT "/doc/help/"

inherit F_CLEAN_UP;

void create() { seteuid(getuid()); }

void doHelp(object me);

void doBack(object me)
{
    int size;
    string *path;

    if( !me->query("help") ) {
    doHelp(me);
        return;
    }

    path = explode(me->query("help"), "/");
    
    size = sizeof(path);

    if( sizeof(path) && path[sizeof(path)-1] == "" ) size -= 1;

    if( size <= 1 ) {
        me->delete("help");
    } else {
        int i;
        string new_path = "";
        for(i=0;i<size-1;i++)
            new_path += path[i] + "/";
        me->set("help", new_path);
    }
}

void doRoot(object me)
{
    me->delete("help");
    doHelp(me);
}

void folderCheck(string input, object me, mixed *files)
{
    int index;

    if( !input ) {
        tell_object(me, "�п�ܡH");
        input_to("folderCheck", me, files);
        return;
    }
    
    if( sscanf(input, "%d", index) == 1 ) {
        if( !sizeof(files) ) {
            tell_object(me, "�п�ܡH");
            input_to("folderCheck", me, files);
            return;
        } else {
            index--;
            if( index < 0 || index >= sizeof(files) ) {
                tell_object(me, "�п�ܡH");
                input_to("folderCheck", me, files);
                return;
            }
        }
    } else {
       if( input == "q" ) return;
       else if( input == "b" ) {
           doBack(me);
           doHelp(me);
           return;
       } else if( input == "r") {
           doRoot(me);
           return;
       } else {
           tell_object(me, "�п�ܡH");
           input_to("folderCheck", me, files);
           return;
       }
    }

    // �O�@�ӥؿ�
    if( files[index][1] == -2 )
        me->set("help", (me->query("help") ? me->query("help"):"") + files[index][0] + "/" );
    else me->set("help", (me->query("help") ? me->query("help"):"") + files[index][0]);

    doHelp(me);
}

mapping getTopic(string dir)
{
    int i = 0;
    string read;
    mapping topic = ([]);
    dir = ROOT + dir + "topic";
    
    while( (read=read_file(dir, i, 1)) ) {
       string eng, chi;
       
       if( sscanf(read, "%s,%s\n", eng, chi) == 2 ) 
          topic[eng] = chi;
       else if( sscanf(read, "%s,%s", eng, chi) == 2 ) 
          topic[eng] = chi;
       i++;
    }

    return topic;
}

void printFolder(object me, string dir)
{
    int i;
    string file;
    mapping topic;
    mixed *files;

    files = get_dir(ROOT+dir, -1);

    if( wizardp(me) ) write(MUD_NAME+"�������A�ثe��m " + HIC+ROOT+HIY+dir+NOR +"\n");
    else write(MUD_NAME+"�������A�ثe��m " + HIW+"/"+dir+NOR + "\n");
    write(HIW"��������������������������������������������������������������������\n"NOR);

    topic = getTopic(dir);

    for(i=0;i<sizeof(files);i++) {
        file = files[i][0];
        
        // �p�G�C�X���O�ؿ��A�[�W�@�� '/'
        if( files[i][1] == -2 ) {
            file += "/";
            write(sprintf(" %2d. "HIC"%-45s "HBK"(%s)\n"NOR, i+1, (undefinedp(topic[file]) ? file : topic[file]), file));
        } else {
            if( file == "topic" )
                write(sprintf(" %2d. "HIB"%-45s "HBK"(%s)\n"NOR, i+1, (undefinedp(topic[file]) ? file : topic[file]), file));
            else write(sprintf(" %2d. "WHT"%-45s "HBK"(%s)\n"NOR, i+1, (undefinedp(topic[file]) ? file : topic[file]), file));
        }
    }

    write(HIW"��������������������������  �^�ڥؿ�("HIY"r"HIW"), �e�@�ӥؿ�("HIY"b"HIW"), ���}("HIY"q"HIW") ����\n"NOR);
    write("�п�ܡH");

    input_to("folderCheck", me, files);
}

void fileCheck(string input, object me)
{

    if( !input ) {
        tell_object(me, "�п�ܡH");
        input_to("fileCheck", me);
        return;
    }
    
    if( input == "q" ) return;
    else if( input == "b" ) {
        doBack(me);
        doHelp(me);
        return;
    } else if( input == "r") {
        doRoot(me);
        return;
    } else {
        tell_object(me, "�п�ܡH");
        input_to("fileCheck", me);
        return;
    }
}

void printFile(object me, string dir)
{
    if( file_size(ROOT+dir) == -1 ) { // �ɮפ��s�b
        me->delete("help");
        doHelp(me);
        return;
    }

    if( wizardp(me) ) write(MUD_NAME+"�������A�ثe��m " + HIC+ROOT+HIY+dir+NOR +"\n");
    else write(MUD_NAME+"�������A�ثe��m " + HIY+"/"+dir+NOR + "\n");
    write(HIW"��������������������������������������������������������������������\n"NOR);

    if( file_size(ROOT+dir) > 1000 ) {
        me->start_more( read_file(ROOT+dir) );
        doBack(me);
    } else {
        write(read_file(ROOT+dir));
        write(HIW"\n��������������������������  �^�ڥؿ�("HIY"r"HIW"), �e�@�ӥؿ�("HIY"b"HIW"), ���}("HIY"q"HIW") ����\n"NOR);
        write("�п�ܡH");
        input_to("fileCheck", me);
    }
}

void doHelp(object me)
{
    int size;
    string dir;
    
    if( !(dir = me->query("help")) ) dir = "";

    size = file_size( ROOT+dir );
    
    if( size == -1 ) {        // �ɮפ��s�b
        me->delete("help");
        printFolder(me, "");  // ��ܮڥؿ�
    } else if( size == -2 ) { // �O�@�ӥؿ�
        printFolder(me, dir); // ��ܥثe���ؿ�
    } else {                  // �ɮצs�b
        printFile(me, dir);   // ����ɮפ��e
    }
}

int main(object me, string arg)
{
        int i;
          string file, *search,*default_search, help;
        if(wizardp(me)) default_search = WIZARD_SEARCH_PATHS;
        else default_search = DEFAULT_SEARCH_PATHS;
        // If no topic specified, give the topics.

    if( !arg ) {
        doHelp(me);
        return 1;
    }

    help = arg[1..strlen(arg)-1];

    if( file_size(ROOT+help) == -1 ) {    //�ɮפ��s�b
        if( wizardp(me) ) {
            if( file_size(arg) == -1 ) { //�ɮפ��s�b
                notify_fail("�S���o�ӻ������C\n");
            } else {
                if( sscanf(arg, ROOT+"%s", help) == 1 ) {
                    me->set("help", help);
                    doHelp(me);
                    return 1;
                } notify_fail("�S���o�ӻ������C\n");
            }
        } else notify_fail("�S���o�ӻ������C\n");
    } else {
        me->set("help", help);
        doHelp(me);
        return 1;
    }

/*
        if( !arg ) {
                msg=read_file(HELP_DIR + "help/topics");
//              if(me->query_temp("gb_player")) msg=LANGUAGE_D->Big52GB(msg);
                me->start_more(msg);
                return 1;
        }
*/
        // Else, try if a command name is specified.
        seteuid(getuid());
        if( stringp(file = me->find_command(arg)) ) {
                notify_fail("���o�ӫ��O�s�b�M���O�èS���ԲӪ��������C\n");
                return file->help(me);
        }

        // Search the individual search path first.
        if( pointerp(search = me->query("help_search_path")) ) {
                i = sizeof(search);
                while(i--) if( file_size(search[i] + arg)>0 ) {
                        me->start_more( read_file(search[i] + arg) );
                        return 1;
                }
        }

        // Support efun/lfun help with same name as other topics such as
        // ed() and ed command.
        sscanf(arg, "%s()", arg);

        // Finally, search the default search paths.
        if( pointerp(default_search) ) {
                i = sizeof(default_search);
                while(i--) if( file_size(default_search[i] + arg)>0 ) {
                        me->start_more( read_file(default_search[i] + arg) );
                        return 1;
                }
        }

        return notify_fail("�S���w��o���D�D���������C\n");
}

int help(object me)
{
        write(@HELP
���O�榡�G
    help                 �i�J help �˯��\��
    help <���O>          �Ҧp�Rhelp score
    help <����m>      �Ҧp�Rhelp /rules  (�]�i�H�O�@�ӥؿ�)

�o�ӫ��O���ѧA�w��Y�@�D�D���Բӻ������M�Y�O�����w�D�D�M�h���ѧA�����D�D
�����M�Ҧ����D�D�P��ƦW�٬Ҭ��^��C

HELP
        );
        return 1;
}