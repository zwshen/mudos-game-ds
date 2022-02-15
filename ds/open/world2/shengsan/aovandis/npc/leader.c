
inherit NPC;
void make_mark();

void create()
{
	set_name("�u�ö�����",({"leader"}) );
	set("long","�L���b�o�̨��ޡA�H�T�O�������w���C\n");		
	set("age",29);
	set("level",22);
	set("race","�H��");
	set("evil",-5);
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",3);
	set("chat_msg",({
		(:command("say ť���̪�`�`���@�s�����W���Ǫ��X�S�b���Z�}�������~�A�ЦU��ȫȭn�p�ߡI"):),
		(:command("hmm"):),
		(: this_object(), "random_move" :),
	})	);

	set("chat_chance_combat", 20);
	set("chat_msg_combat", ({
		(:command("say ���F���@���Z�}�����w���A�ڡA�u�ö������A�n�N�@�ê̴N�a���k�I�I"):),
		(: make_mark :),
	}) );
	set_skill("dodge",30);
	set_skill("block",30);
	set_skill("parry",30);
	set_skill("unarmed",30);
	set_skill("sword",30);

	set("talk_reply","��Ať���̪�`�`���@�s�����W���Ǫ��X�S�b���Z�}�������~�C�ڷ|�ɤO�O�@�o�y�������C");
	setup();

	carry_object(__DIR__"wp/typicalsword")->wield();
	carry_object(__DIR__"eq/typicalwrists")->wear();
	carry_object(__DIR__"eq/typicalhelmet")->wear();
	carry_object(__DIR__"eq/typicalglove")->wear();

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
		kill_ob(this_player());
	}
}

void make_mark()
{
	object *enemy, ob;
    command("say �ܡI�ݧڪ��F�`�I");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"�A�A�O���]���C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}
