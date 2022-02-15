// In room085.c ������|
inherit NPC;

void make_mark();

void create()
{
	set_name("�~����v",({"doctor"}) );
	set("long","�o�O�@����R�~����v�A���h�ϤH���z�Q�ӧV�O�ۡC\n");		
	set("age",28);
	set("level",20);
    set("con",14);
	set("race","�H��");
	set("gender","�k��");
	set("evil",-15);	// ���c�� -15 (�������c, �t���})
	set("exp_point",0);	// �]�w�j��, exp��combat_exp�|�ѦҨ�o�ӭ�
				// 0 <= exp_point <= 9
				// ���w�Ȭ� 0 , �Ш̾ڱj�רӳ]�X�z����...
	set("chat_chance",5);
	set("chat_msg",({
		(:command("say ��N�M�b�ڤ�W�A�O�S�����i�઺�ƪ��I"):),
		(:command("smile"):),
		(:command("hi"):),
	})	);

	set("chat_chance_combat", 40);
	set("chat_msg_combat", ({
		(: make_mark :)
	}) );
	set_skill("dodge",60);
	set_skill("block",60);
	set_skill("parry",60);
	set_skill("unarmed",60);

	set("talk_reply","�١A�ڱߤW�n�I���C�����ڧa�C�ڪ��q�ܬO0204777777�C");
	setup();

	add_money("dollar",100);
}

void make_mark()
{

	object *enemy, ob;
	if( random(30)%2 )
		command("say �z�I�A�o�ӥi�c���a�H�A�n�h��I");
	else
		command("peace");

	enemy = query_enemy();
	if( sizeof(enemy) ) ob = enemy[random(sizeof(enemy))];
	if(!ob) return;
	
	if( this_object()->query("helpready/"+ob->query("id")) )
		return;

	command("say "+ob->query("name")+"�A�A�O���]���C");

	ob->add_temp("quest/aovandis",1);	// �N�ۭt�������H���W�аO

	this_object()->set("helpready/"+ob->query("id"),1);	// �P id ����

}
