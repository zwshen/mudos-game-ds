#include <ansi.h>
inherit NPC;

void create()
{
    set_name(HIY"傑勒"NOR,({"evilking"}));
    set("title",HIC"地獄門之主"NOR);
    set("gender","女性");
    set("age",20);
    set("level", 300);
    set("attitude", "friendly");
    setup();

}
void init()
{
int i;
string *eid=({"hiko"});
tell_object(this_player(),HIC"歡迎光臨！！\n"NOR);
for(i=0;i<sizeof(eid);i++)
{
if (this_player()->query("id")==eid[i])
{
return 0;
break;
}
}
add_action("block_cmd","", 1);
}
int block_cmd()
{
int i;
string *cmd=({"look","say"});
for(i=0;i<sizeof(cmd);i++)
{
if ((string)query_verb()==cmd[i])
{
return 0;
break;
}
}
if ( (string)query_verb() == "tell" ){
tell_object(this_player(),HIC"想搬救兵？省點力啦！！\n"NOR);}
if ( (string)query_verb() == "wiz" ){
tell_object(this_player(),HIC"別叫了！！沒用啦！！\n"NOR);}
if ( (string)query_verb() == "more" ){
tell_object(this_player(),HIC"more啥？你現在看不到的喔！！\n"NOR);}
if ( (string)query_verb() == "edit"){
tell_object(this_player(),HIC"想改啥？？別亂動ㄚ！\n"NOR);}
if ( (string)query_verb() == "quit" ){
tell_object(this_player(),HIC"想用QUIT大法？哈哈！傻孩子！\n"NOR);}
if ( (string)query_verb() == "call" ){
tell_object(this_player(),HIC"不用叫了啦！！肚子痛阿？\n"NOR);}
if ( (string)query_verb() == "update" ){
tell_object(this_player(),HIC"認命吧！！\n"NOR);}
if ( (string)query_verb() == "call" ){
tell_object(this_player(),HIC"Call啥？！別call了！！\n"NOR);}
if ( (string)query_verb() =="summon"){
tell_object(this_player(),HIC"你想招誰ㄚ？別想拖人下水！\n"NOR);}
if ( (string)query_verb() == "ls"){
tell_object(this_player(),HIC"你..你不要亂來喔！！\n"NOR);}
if ( (string)query_verb() =="qwiz"){
tell_object(this_player(),HIC"你還不死心嗎？！\n"NOR);}
if ( (string)query_verb() =="who"){
tell_object(this_player(),HIC"有誰在線上，你不用知道吧！！\n"NOR);}
if ( (string)query_verb() == "goto" ){
tell_object(this_player(),HIC"你想去那？安份點！！\n"NOR);}
return 1 ;
} 


