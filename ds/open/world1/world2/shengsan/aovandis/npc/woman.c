// In room076.c ¾�~���Щ�
inherit NPC;

void make_mark();

void create()
{
	set_name("���~���H",({"woman"}) );
	set("long","�o�줤�~���H���b�줽�C\n");		
	set("age",38);
	set("level",11);
	set("race","�H��");
	set("gender","�k��");
	set("evil",-5);		// ���c�� -5 (�������c, �t���})
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",2);
	set("chat_msg",({
		(:command("say �̪�ӨD¾���H���V�ӶV�h�F�H"):),
		(:command("hmm"):),
	})	);

	set("chat_chance_combat", 50);
	set("chat_msg_combat", ({
		(: make_mark :),
	}) );
	set_skill("dodge",10);
	set_skill("block",10);
	set_skill("parry",10);
	set_skill("unarmed",10);

	set("talk_reply","��A�o�O�y���R�������C�аO�o���n�å�U����C");
//       set("inquiry/name","�A�n�A�ڬO���Z�}�����u�ö��`�q�O�A�W�s�ȯS");
	setup();

	add_money("dollar",200);
}

void make_mark()
{
	object *enemy, ob;

	if(random(30)%2)
		command("say �z�I�ϩR���I");
	else
		command("sob");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;

	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"�A�A�O���]���C");
	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO
	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}
