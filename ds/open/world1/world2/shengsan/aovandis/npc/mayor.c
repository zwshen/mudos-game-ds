
inherit NPC;
void make_mark();

void create()
{
	set_name("���Z�}������",({"mayor"}) );
	set("long",
"�o�쥫�����۷��R�L���������A�Mħ�i�˪����e���Aı�o�L�O��n�����C\n"
	);		
	set("age",45);
	set("level",20);
	set("attitude", "heroism");
	set("race","�H��");
	set("evil",-20);
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say �w��Ө���Z�}���A�o�O�y���R�������A�кɿ������a�I"):),
		(:command("smile"):),
	})	);

	set("chat_chance_combat", 60);
	set("chat_msg_combat", ({
		(:command("say �ϩR�ڡA���H�y�ϤF�I�I"):),
		(: make_mark :),
	}) );
	set_skill("dodge",50);
	set_skill("parry",50);
	set_skill("unarmed",50);

	setup();

	carry_object(__DIR__"eq/redglazedring")->wear();
	add_money("dollar",50);
}


void make_mark()
{
	object *enemy, ob;
	command("say �z�I�ϩR���I");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"�A�A�O���Z�}�����ĤH�C");
	ob->add_temp("quest/aovandis",3);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}
