
public class Main {
    public static void main(String[] args) {

        // jangan mengubah isi fungsi main ini kecuali untuk mengetes
        // ketika dikumpulkan, isi fungsi main harus seperti saat awal

        Warrior aragorn = new Warrior();
        aragorn.setName("Aragorn");
        aragorn.setHitPoint(120);

        Weapon anduril = new Weapon();
        anduril.setName("Anduril Sword");
        anduril.setDamage(50);
        aragorn.setWeapon(anduril);

        Enemy orcs = new Enemy();
        orcs.setName("Uruk-Hai");
        orcs.setHitPoint(70);

        while (orcs.getHitPoint() > 0) {
            aragorn.attack(orcs);
            orcs.decreaseHitPoint(aragorn.getWeapon().getDamage());
        }

        if (orcs.getHitPoint() <= 0) {
            orcs.die();
        }

        Warrior legolas = new Warrior();
        legolas.setName("Legolas");
        legolas.setHitPoint(100);

        RangedWeapon bow = new RangedWeapon();
        bow.setName("Mirkwood Bow");
        bow.setDamage(50);
        bow.setRange(200);
        legolas.setWeapon(bow);

        Enemy nazgul = new Enemy();
        nazgul.setName("Nazgul Dragon");
        nazgul.setHitPoint(200);
        nazgul.setAbility("flying");

        nazgul.castAbility();

        while (nazgul.getHitPoint() > 0) {
            legolas.attack(nazgul);
            nazgul.decreaseHitPoint(legolas.getWeapon().getDamage());
        }

        if (nazgul.getHitPoint() <= 0) {
            nazgul.die();
        }
    }
}
