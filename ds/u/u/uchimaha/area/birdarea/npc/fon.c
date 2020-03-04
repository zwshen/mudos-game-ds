#include <ansi.h>
inherit NPC;
void create()
{
 set_name("���W��",({"shin-do-fon","fon"}));
 set("long",@LONG
���H��������, �C������, �Y�v�ܪ�, �L���٦׵���,
�������o�Xģ��������, �N�����N�@��, �@�ݴN���D��
�H���\����, �H�٤ѱ��T�t���@, �S�� [ ��p�� ] �]
���L�����\�i�H��O��F���G��ޤF, ���H�O�ѱ��и�
�M�𻴥\������A�L�D�`���w�������Y�C
LONG
);
 set("attitude","peaceful"); 
 set("age",42);
 set("gender","�k��");
 set("level",38);
 set("title",HIC"�ѱ��T�t"NOR);
 set("class1","�ѱ���");
 set_skill("dagger",70);
 set_skill("dodge",100);
 set_skill("bird-eight",100);
 set_skill("force",60);
 set_skill("parry",60);
 set_skill("sky-dagger",70);
 map_skill("dagger","sky-dagger");
 map_skill("dodge","bird-eight");
 set("guild_gifts",({6,4,0,10}));
 set("guild_skills",([
     "bird-eight" : ({ 140,3,80 }),
 ]));
 set("chat_chance",9);
 set("chat_msg", ({"���W���Į𻡹D:����ڲ��ͪ����@���M����p�@�H�v?\n",
                   "���W���Į𻡹D:�N�u�t���@�ӤF�C\n",
                   (:command("sigh"):),
 }));
 set("chat_chance_combat",80);
 set("chat_msg_combat",({(:command,"exert sky-dagger":),
                         (:command,"say �p�l!!�A���n�R�F!!�h���a!! ":),
 }));
 set("talk_reply","�A�����ڤ@�I��(help)��?\n");
 set("inquiry/help","�ЧA���ڧ�줭�m�ۡA�u���������Y�ڨS���C\n");
 setup();
 carry_object(__DIR__"eq/dagger3")->wield();
 carry_object(__DIR__"eq/cloth2")->wear();
 carry_object(__DIR__"eq/boots2")->wear();
 carry_object(__DIR__"eq/surcoat")->wear();
}
int do_skill_list(string arg)
{
        return GUILDMASTER->do_skill_list(this_object(),this_player(),arg);
}
int do_skill_train(string arg)
{
        
        if( arg=="bird-eight" )
        {
                if( this_player()->query_skill( "bird-eight", 1 ) == 0 )
                return notify_fail("�A�èS���ǹL�򥻨B�Z�A���m�٬O�S�Ϊ��C\n");
        }
        return GUILDMASTER->do_skill_train(this_object(),this_player(),arg); 
}
int accept_object(object who,object ob)
{
        object obj;
        obj=this_object();
        if( ob->query("id") != "five color stone" )
{
           command("slap "+who->query("id"));
           command("say �A���ڳo�ӬOԣ��....-.-");
           return 0;
}
        else {
           if(obj->is_busy() )
           {
             command("whisper "+who->query("id")+" �ڥ��b���A�ЧA���@�U�C\n");
             return 0;
           }
             message_vision("$N���F���W���@�� "+ob->query("name")+"�C\n",who);
             command("think");
             obj->start_busy(10);
             obj->set_temp("givehat",1);
             destruct(ob);
             call_out("givehat",1,who);
return 1;
        }
}
void givehat()
{
      int i;
object me,obj,plate;
      me=this_player();
      obj=this_object();
      i=obj->query_temp("givehat");
      if( !me || environment(me) != environment(obj) )
        {
                command("say �x�H" + RANK_D->query_respect(me) + "�H�O�H�H");
                return;
        }
      switch( i ) {
          case 1:
            say(HIY"���W���Τ⻴����Ĳ�N�o�����Y�C\n"NOR);
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 2:
            command("say �N�O�o��....�u�O���§A�F�A�o�줯�S�C");
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            break;
          case 3:
            say(HIY"���W���p�ߪ��⤭�m�۵����_�ӡC\n"NOR);
            command("jump");
            obj->set_temp("givehat",i+1);
            call_out("givehat",3,me);
            break;
          case 4:
            if(me->query("class1") == "�ѱ���" && me->query_skill("bird-eight") == 0)
            {
                 command("say �ѤҬݧA�@���H�~�A�K�ЧA�X�⻴�\\�A��O����§�n�F�C");
                 obj->set_temp("givehat",i+1);
                 call_out("givehat",3,me);
            }
            else {
                 command("say �u�i��....");
                 command("sigh");
                 command("say �ڷ|���j�a�����D�A�����U�L��");
                 command("bow");
                 me->add("exp",5000);
                 tell_object(me,HIW"(�]���A���U�F�D�W���A�ҥH�o��F 5000 �IEXP�C)\n"NOR);
                 obj->delete_temp("givehat");
                 }
            break;
          case 5:
            say(HIG"�u�����W���@��b�󤤸��D���R�A�@������۫l�D�B�ۦ��C\n"NOR);
            message_vision(" ( $N�c�c���O�U�Ҧ����ۦ� )\n",me);
            me->set_skill("bird-eight",10);
            obj->set_temp("givehat",i+1);
            call_out("givehat",5,me);
            break;
          case 6:
            command("say �n�F�n�F�A�A�ۤv�h�m�ߧa....:D");
            obj->set_temp("givehat",i+1);
            call_out("givehat",2,me);
            obj->delete_temp("givehat");
            break;
          }
}
void die()
{
object ob;
        if( !ob = query_temp("last_damage_from") )
        ob = this_player(1);
        LOGIN_D->set_reboot(0);
        if( ob ) message("world:world1:vision", HIW"\n  �Z�L�ǥX�F�@�h��H������:"HIC"\n\n\t�ѱ��T�t���@�� ���W�����M�ѵ��F"+ob->name(1)+"�C\n\n"+NOR,users());
        ob->add("popularity",2);
        tell_object(ob,HIW"(�]���A�����F���W���A�ҥH�o��F 2 �I�n��C)"NOR);
        ::die();
        return;
}
