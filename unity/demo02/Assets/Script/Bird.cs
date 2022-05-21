using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class Bird : MonoBehaviour
{
    public Vector2 bird_velocity = new Vector2(0, 5);
    public Sprite[] birdSprites;
    
    public float timer = 0;
    
    public AudioSource fly;

    public AudioSource getScore;

    public AudioSource dead;
    private int dead_timer = 0;

    public float Score = 0;
    public Text scoreText;

    

    // Start is called before the first frame update
    void Start()
    {
        if(scoreText != null){
            scoreText.text = Score.ToString();
        }
        this.gameObject.GetComponent<Rigidbody2D>().gravityScale = 0;
    }
 
    // Update is called once per frame
    void Update()
    {

        if(GameManager._gameManager.gameState != GameState.Running) return;

        if(Input.GetMouseButtonDown(0)){

            this.GetComponent<SpriteRenderer>().sprite = birdSprites[1];
            timer = 0;
            Rigidbody2D rigid = this.gameObject.GetComponent<Rigidbody2D>();
            if(rigid != null){
                rigid.velocity = bird_velocity;
                
                if(fly != null){
                    fly.Play();
                }  
            }  
        }
        else{
            if(timer == 25){
                this.GetComponent<SpriteRenderer>().sprite = birdSprites[0];
                
            }
            timer++;
        }
    }

    //碰撞
    private void OnCollisionEnter2D(Collision2D collision){
        //死亡
        GameManager._gameManager.gameState = GameState.Gameover;
        if (dead != null && dead_timer == 0) { 
            dead.Play();
            dead_timer++;
        }
        this.GetComponent<SpriteRenderer>().sprite = birdSprites[2];
        GameManager._gameManager.restartButton.gameObject.SetActive(true);
    }

    //脱离
    private void OnTriggerExit2D(Collider2D collision){
        //加分
        if(collision.gameObject.CompareTag("ScorePipeline")){
            Score += 1;
            if(scoreText != null){
                scoreText.text = Score.ToString();
            }

            if(getScore != null){
                getScore.Play();
            }
        }

        
    }




}
