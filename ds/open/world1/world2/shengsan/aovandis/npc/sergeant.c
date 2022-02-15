// In room058.c	���߼s���F�_��
// ��s���: 1999.10.15
// ��s��: Luky
// QCer: Luky
#include <ansi.h>
inherit NPC;
inherit SSERVER;
void make_mark();
void cast_mind();

void create()
{
	set_name("���G",({"yin-bian","bian"}) );
	set("long","�L�O���Z�}���̦��W���צ�̡Ať���L�֦��W��O�C\n");
	set("age",30);
	set("level",40);
	set("race","�H��");
	set("guild_gifts",({3,4,8,5}));
	set("evil",-10);
	set("exp_point",4);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",8);
	set("chat_msg",({
		(:command("say �o�O�y���R�������A�Ф��n���X�H�k���Ʊ���I"):),
		(:command("smile"):),
		(: this_object(), "random_move" :),
		(: this_object(), "random_move" :),
		(: this_object(), "random_move" :),
	})	);

	set("chat_chance_combat", 47);
	set("chat_msg_combat", ({
		(:command("say ���F���@���Z�}�����w���A�ڨ������x�A�@�w�n�N�@�ê̴N�a���k�I�I"):),
		(: make_mark :),
		(: cast_mind :),
//		(:command("cast mindkill"):),
	}) );
	set_skill("dodge",30);
	set_skill("block",30);
	set_skill("parry",30);
	set_skill("unarmed",30);
//	set_spell("mindkill",70);
	set_skill("staff",70);

	set("talk_reply","��A�o�O�y���R�������C�аO�o���n�å�U����C");
	setup();

	carry_object(__DIR__"eq/aihun_robe")->wear();
	carry_object(__DIR__"wp/staff0")->wield();
	add_money("dollar",200);
}

void init()
{
	object ob = this_player();
	::init();
	if(!this_object()->is_killing(ob->query("id")) && ob->query_temp("quest/aovandis") > 2 + random(3) )
	{
		command("say �A�o�ӧ@�ê̡A�~�M���D�@��A���ѳQ�ڹJ���A�˷��C");
		ob->add_temp("quest/aovandis",-2);
		kill_ob(this_player());
	}

}


void make_mark()
{
	object *enemy, ob;
//	command("say �z�I�ϩR���I");
	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say ��!�L�k�L�Ѫ�"+ob->query("name")+", �ڵo�}�n�N�A�v�X���Z�}���C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}

void cast_mind()
{
	object ob,me;
	int damage,c;

	me = this_object();

	ob = offensive_target(me);
	if(!ob) return;
	if(me->query("mp")<20) return;
	me->receive_damage("mp",20);
	command("say "+ob->query("name")+"�A���A�ݬݧڶW��O���Q�`�C");


	tell_room(environment(me),"\n"+me->query("name")+"��M���l����h�F�@�B\n");
	tell_room(environment(me),"\n�A�ݨ�L������۵M�����U�A�����ܱo���`�������C\n");

	if( ob->query_int() < random(150) )
	{
	    ob->add_busy(2);
	    message_vision(HIR"\n$N��M��P�D�����ҥR���ۮ��ߡA$N����ʦn���Q�����F�C\n",ob);
	    damage = random(100)+query_int()*3;
	    damage = damage/3+random(damage/2);
	    c=ob->quer_shield();
	    damage = damage-c/2-random(c/2);
	    if(damage<0) damage=0;
	    damage = COMBAT_D->Merits_damage(me,ob,damage,"sou");
	    ob->receive_damage("hp", damage, me );
	    if(damage>0)
	    	message_vision(HIR"\n$N��M�Q���W���O�q�ҥ����A�f�R�A��A��ӤH�Q���b����W�ʼu���o�C\n"NOR,ob);
	    else
		message_vision(HIW"\n�ѩ�$N���F�O�ӹL "+me->query("name")+" �@�w�A���ͥͦa���U�F�o�Ѳ��W���O�C\n"NOR,ob);

	    if(me->query_temp("apply/show_damage") || me->query_temp("show_damage") )
	        tell_object(me,HIY"("+damage+")"NOR);
	    if(ob->query_temp("apply/show_damage") || ob->query_temp("show_damage") )
	        tell_object(ob,HIR"("+damage+")"NOR+" ("+ob->query("hp")+"/"+ob->query("max_hp")+")");
	    message_vision("\n",ob);
	    if(wizardp(ob) && ob->query("env/debug"))
	        tell_object(ob,"  �y��"+damage+"�I�ˮ`!!\n"); 
	    COMBAT_D->report_status(ob);	

	}
	else message_vision("\n���W���O������V$N�A���G�Q$N���F���ƸѤF�C\n",ob);

 	me->start_busy(1);

}