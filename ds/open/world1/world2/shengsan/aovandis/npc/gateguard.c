// In room009.c ���Z�}�������� room016.c �F������ room033.c �谼����
inherit NPC;
void make_mark();

void create()
{
	set_name("�˧L",({"military policeman","policeman"}) );
	set("long","�@�Ӱ��j���˧L���b�o�̺ʵ��۶i�X�������i�äH���C\n");		
	set("age",25);
	set("level",26);
	set("race","�H��");
	set("evil",-1);
	set("exp_point",1);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",10);
	set("chat_msg",({
		(:command("say �w��Ө���Z�}���A�o�O�y���R�������A�Ф��n���X�H�k���Ʊ���I"):),
		(:command("hmm"):),
	})	);

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(:command("say ���F���@���Z�}�����w���A�ڵ��藍�|���A�p���k�~�I�I"):),
		(: make_mark :),
	}) );
	set_skill("dodge",60);
	set_skill("block",20);
	set_skill("parry",20);
	set_skill("unarmed",20);
	set_skill("axe",40);

	set("talk_reply","��A�o�O�y���R�������C�аO�o���n�å�U����C");
	setup();

	carry_object(__DIR__"wp/typicalaxe")->wield();
	carry_object(__DIR__"eq/typicalshield")->wear();
	carry_object(__DIR__"eq/typicalboot")->wear();

}

void init()
{
	object ob = this_player();
	::init();
	if(!this_object()->is_killing(ob->query("id")) && ob->query_temp("quest/aovandis") > 1 + random(3) )
	{
		command("say �A�o�ӧ@�ê̡A�~�M���D�@��A���ѳQ�ڹJ���A�˷��C");
		ob->add_temp("quest/aovandis",-2);
		kill_ob(this_player());
	}
	else if(ob->query("evil") > 600 && random(2))
		command("say "+ob->query("name")+"�A�o�̤��w�器�c���H�A�о������}���Z�}���a�C");
}

void make_mark()
{
	object *enemy, ob;
	command("say �A�����աI�ǩR�ӡC");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

        command("say �h���a�C"); // change msg by alickyuen
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}
