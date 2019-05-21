package routers

import (
	"github.com/astaxie/beego"
	"github.com/killin10/playground/golang/beegoapp/controllers"
)

func init() {
	beego.Router("/", &controllers.MainController{})
}
