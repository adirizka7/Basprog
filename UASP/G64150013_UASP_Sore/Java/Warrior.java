public class Warrior extends Character {
	
	Weapon weapon;
	
	public Warrior() {
	}
	
	@Override
	public void decreaseHitPoint(int amount) {
	}
	
	public void setWeapon(Weapon weapon) {
		this.weapon = weapon;
	}
	
	
	public void attack(Enemy musuh) {
		System.out.println("Warrior " + this.name + " attacks " + musuh.name + " using " + this.weapon.name);
	}
	
	public Weapon getWeapon() {
		return weapon;
	}
}
