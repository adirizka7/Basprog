public abstract class Character {
	
	protected String name;
	protected int HitPoint;
	
	public Character() {
	}
	
	public void setName(String name) {
		this.name = name;
	}
	
	public void setHitPoint(int HitPoint) {
		this.HitPoint = HitPoint;
	}
	
	public abstract void decreaseHitPoint(int amount);
}
