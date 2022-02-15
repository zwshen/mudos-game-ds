inherit NPC;

void make_mark();

void create()
{
	set_name("����ĵ��",({"patrol"}) );
	set("long","�@��ĵ�å��b�o�̨��ޡC�o��ĵ�åR���F���q�P�C\n");		
	set("age",30);
	set("level",24);
	set("race","�H��");
	set("evil",-5);
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",10);
	set("chat_msg",({
		(:command("say ��H�_�ǡA�ڤ߷R��ĵ���]����h�F�O�H"):),
		(:command("hmm"):),
		(:command("get all"):),
		(:random_move():),
		(:random_move():),
		(:random_move():),
	})	);

	set("chat_chance_combat", 10);
	set("chat_msg_combat", ({
		(:command("say ���F���@���Z�}�����w���A�ڡA����ĵ�áA�n�N�@�ê̴N�a���k�I�I"):),
		(: make_mark :),
	}) );
	set_skill("dodge",30);
	set_skill("block",30);
	set_skill("parry",30);
	set_skill("unarmed",30);
	set_skill("staff",70);
	set("random_move",1);
	set("talk_reply","��A�o�O�y���R�������C�аO�o���n�å�U����C");
	setup();

	carry_object(__DIR__"wp/club1")->wield();
	carry_object(__DIR__"eq/patrolarmor")->wear();

	add_money("dollar",50);
}

void init()
{
	object ob = this_player();
	::init();
	if(!this_object()->is_killing(ob->query("id")) && ob->query_temp("quest/aovandis") > 1 + random(3) )
	{
		command("say �A�o�ӧ@�ê̡A�~�M���D�@��A���ѳQ�ڹJ���A�˷��C");
		ob->add_temp("quest/aovandis",-2);
		command("follow "+ob->query("id"));
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

	command("say �N "+ob->query("name")+" ���J�a���C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}
