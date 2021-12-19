#include "Dealer.h"

void Dealer::Mixing(Deck* Cards)
{
	int index, n = Cards->countCards;

	Card tmp;
	for (int i = 0; i < Cards->countCards; i++)
	{
		index = rand() % n;

		tmp = Cards->cards[index];

		Cards->SetCard(index, Cards->cards[i]);
		Cards->SetCard(i, tmp);
	}
}

bool Dealer::CheckBlackJack(HandDeck* handPlayer)
{
	int n = handPlayer->GetCountCard();
	if (n != 5) return false;

	for (int i = 0; i < n; i++)
		if (handPlayer->GetCard(i)->GetPower() > 5) return false;

	return true;
}

bool Dealer::CheckSplit(Player* player)
{
	return (GetPlayerDeck(player)[0].GetCountCard() && GetPlayerDeck(player)[0].GetCard(0)->GetPower() == GetPlayerDeck(player)[0].GetCard(1)->GetPower());
}

void Dealer::Split(HandDeck* playerDeck, Deck* gameDeck)
{
	Card* tmpCard = playerDeck[0].GetCard(1);
	playerDeck[1].AddCard(tmpCard);
	playerDeck[0].power -= tmpCard->GetPower();
	playerDeck[0].RemoveLastCard();

	playerDeck[0].AddCard(gameDeck->GetCard(gameDeck->GetCountCard() - 1));
	gameDeck->RemoveLastCard();

	playerDeck[1].AddCard(gameDeck->GetCard(gameDeck->GetCountCard() - 1));
	gameDeck->RemoveLastCard();
}

HandDeck* Dealer::GetPlayerDeck(Player* player) { return player->hand; }
HandDeck* Dealer::GetDeck() { return &this->hand; }
int Dealer::GetPowerDeck(HandDeck* handDeck) { return handDeck->power; }