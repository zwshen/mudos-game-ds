inherit NPC;

void make_mark();

void create()
{
	set_name("�ȯS",({"art"}) );
	set("long","�ȯS�O���Z�}�����u�ö��`�q�O�A�L����ɭ���Q��L�u�ö��������Ҫ֩w�C\n");		
	set("age",40);
	set("level",30);
	set("attitude", "heroism");
	set("race","�H��");
	set("evil",-20);	// ���c�� -20 (�������c, �t���})
	set("exp_point",3);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say �u�@�o�y���R�������O�ڪ��d���I"):),
		(:command("smile"):),
	})	);

	set("chat_chance_combat", 30);
	set("chat_msg_combat", ({
		(:command("say ���F���@���Z�}�����w���A�ڡA�u�ö��`�q�O�A�n�N�@�ê̴N�a���k�I�I"):),
		(: make_mark :)
	}) );
	set_skill("dodge",60);
	set_skill("block",60);
	set_skill("parry",50);
	set_skill("unarmed",80);
	set_skill("sword",80);

	set("talk_reply","��A�o�O�y���R�������C�аO�o���n�å�U����C");
	set("inquiry/name","�A�n�A�ڬO���Z�}�����u�ö��`�q�O�A�W�s�ȯS");
	setup();

	carry_object(__DIR__"wp/artsword")->wield();
	carry_object(__DIR__"eq/drangonshield")->wear();
	add_money("dollar",50);
}

void init()
{
	object ob = this_player();
	::init();
	if(!this_object()->is_killing(ob->query("id")) && ob->query_temp("quest/aovandis") > 3 + random(3) )
	{
		command("say �A�o�ӧ@�ê�"+ob->name(1)+"�A�~�M���D�@��A���ѳQ�ڹJ���A�˷��C");
		ob->add_temp("quest/aovandis",-2);
		kill_ob(this_player());
	}
}

void make_mark()
{
	object *enemy, ob;
	command("say �ܡI�ݩۡI");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"�A�A�o�ӸӦ����å�C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}
