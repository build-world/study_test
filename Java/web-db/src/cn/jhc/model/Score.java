package cn.jhc.model;

import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.ManyToMany;
@Entity
public class Score {
	private ScorePK pk;
	private float uscore;
	private float endScore;
	
	public ScorePK getPk() {
		return pk;
	}
	public void setPk(ScorePK pk) {
		this.pk = pk;
	}
	public float getUscore() {
		return uscore;
	}
	public void setUscore(float uscore) {
		this.uscore = uscore;
	}
	public float getEndScore() {
		return endScore;
	}
	public void setEndScore(float endScore) {
		this.endScore = endScore;
	}

	
}
