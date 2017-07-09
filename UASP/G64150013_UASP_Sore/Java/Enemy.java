public class Enemy extends Character {
	
	protected String ability;
	
	public Enemy() {
	}
	
	public int getHitPoint() {
		return HitPoint;
	}
	
	@Override
	public void decreaseHitPoint(int amount) {
		System.out.println("Enemy " + this.name + " loses " + amount + " hit point");
		this.HitPoint = this.HitPoint - amount;
	}
	
	public void die() {
		System.out.println("Enemy " + this.name + " dies");
	}
	
	public void setAbility(String ability) {
		this.ability = ability;
	}
	
	public void castAbility() {
		System.out.println("Enemy " + this.name + " is flying");
	}
}
