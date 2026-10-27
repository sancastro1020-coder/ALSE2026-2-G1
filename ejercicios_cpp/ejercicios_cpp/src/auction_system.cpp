#include <iostream>
#include <unordered_map>
using namespace std;
class AuctionSystem {
    // itemId -> (userId -> bidAmount)
    unordered_map<int, unordered_map<int, int>> ofertas;
public:
    void addBid(int userId, int itemId, int bidAmount) { ofertas[itemId][userId] = bidAmount; }
    void updateBid(int userId, int itemId, int newAmount) { ofertas[itemId][userId] = newAmount; }
    void removeBid(int userId, int itemId) { ofertas[itemId].erase(userId); }
    int getHighestBidder(int itemId) {
        auto it = ofertas.find(itemId);
        if (it == ofertas.end() || it->second.empty()) return -1;
        int mejorUsuario = -1, mejorOferta = -1;
        for (const auto& [usuario, oferta] : it->second) {
            if (oferta > mejorOferta || (oferta == mejorOferta && usuario > mejorUsuario)) {
                mejorOferta = oferta; mejorUsuario = usuario;
            }
        }
        return mejorUsuario;
    }
};
int main() {
    AuctionSystem s; s.addBid(4, 10, 150); s.addBid(7, 10, 150); s.addBid(3, 10, 120);
    cout << "Mayor postor: " << s.getHighestBidder(10) << '\n';
}
