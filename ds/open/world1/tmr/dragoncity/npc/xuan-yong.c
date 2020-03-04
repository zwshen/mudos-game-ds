#include <ansi.h>
inherit F_MASTER;
inherit NPC;
void combat_ai();

void create()
{
        set_name("�ť�" , ({ "xuan yong master", "mo", "xuan","yong", "master" }) );
        set("long",@long
�ťìO�֫ӭx���������l�A���H���֦��~��A��֫ӱF������`��
��A���ӫ�w�C�p���L����֫ӭx�s�L���۹��u�@�A�p�G�A���N�[�J��
�ӭx�A�i�H��L�n�D�[�J(join army)�C
long
);
        create_family( "�֫ӭx", 2, "�N�x");
        set("level", 40);
        set("race","human");
        set("age",45);
        set("class1","�֫ӭx");
        set("gender","�k��");
        set("adv_class",1);
        set("guild_gifts",({8,8,0,4}));

        set_skill("unarmed",100);
        set_skill("blade",100);
        set_skill("bloodwar-blade",100);
        set_skill("flybird-steps",100);
         map_skill("dodge","flybird-steps");
         map_skill("blade","bloodwar-blade");

        set("guild_skills",([
               "bloodwar-blade" : ({130,3,70}),
               "flybird-steps" : ({130,3,80}),
               "nine-mystery" : ({130,3,50}),
               "dodge" : ({120,3,70}),
                 "blade" : ({120,3,70}),
               "parry" : ({130,2,70}),
               "unarmed" : ({130,3,70}),
                 "dragon-fist" : ({100,2,90}),
               "force" : ({130,3,50}),
        ])  );

                set("chat_chance", 5);
        set("chat_msg",({
                (: command("say �{�b��a�����A�O�k�l�~���N�ӥߨ�����I�I") :),
                (: command("smile") :),
        }) );

        setup();
        set_temp("apply/shield",100);
        set_temp("apply/armor",50);
        carry_object(__DIR__"wp/steel-blade")->wield();
}

void init()
{
    ::init();
        add_action("do_skill_list","list");
        add_action("do_skill_train","train");
         add_action("do_join","join");
        add_action("do_advance","advance");
}


int do_skill_list(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        GUILDMASTER->do_skill_list(ob,me,arg);
        return 1;
}

int do_skill_train(string arg)
{
        object ob, me;

        ob = this_object();
        me = this_player();

        return GUILDMASTER->do_skill_train(ob,me,arg);
}

int do_join(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if( me->query("class1") == "�֫ӭx") return notify_fail("�A�w�O�֫ӭx�̤l�F�C\n");
        if( me->query("adv_class") ) return notify_fail("�A�w�O�䥦�������̤l�F�C\n");
        if(arg != "army") return notify_fail("�A�n���J���@�Ӫ���?\n");
        if(me->query("gender")=="�k��") {
                command("shake");
                command("say �p�@�Ӥk������W�Գ����ĩO�C");
                return 0;
        }
        if(me->query_skill("blade")<5) {
                command("shake");
                command("say ���@�A��L�������O�A���W�Գ����ĩO�H�h�m�m�M�k�a");
                return 0;
        }
        command("say �n�n�n�I�I�k�l�~�Ӧb�F���C");
        command("say �A�N�[�J�֫ӭx�A���ۤw�Хߤ@½�j�Ʒ~�a�C");
        command("pat "+me->query("id"));
        me->set("adv_class",1);
        me->set("class1","�֫ӭx");
        me->create_family("�֫ӭx",2,"�x�H");
        me->set("guild_rank","�֫ӭx���ΤM�s��");
    me->set("guild_gifts", query("guild_gifts") );


        return 1;   
}

int do_advance(string arg)
{
        object ob, me;
        ob = this_object();
        me = this_player();
        if (me->query("family/family_name")=="�֫ӭx") return GUILDMASTER->do_advance(ob,me,arg);
        else return notify_fail("�A���O�֫ӭx�l�̧L�C\n");
}

string guild_rank(object me)
{
        string rank;
        int lv;
        lv = me->query("level");
        lv = lv/10;     // �N rank �������Ӽh��
        switch( lv )
        {
                case 0: rank = "�֫ӭx���ΤM�s��"; break;
                case 1: rank = "�֫ӭx���M�k����"; break;
                  case 2: rank = "�֫ӭx����ԨF��"; break;

        }
        return rank;
}
