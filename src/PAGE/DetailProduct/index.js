import React, { useEffect, useState } from "react";

import { Row, Col, Button } from "antd";

import styles from "./styles.module.css";

import { useParams } from "react-router-dom";
import { useDispatch } from "react-redux";
import { useSelector } from "react-redux";
import { Addtocart } from "../../actions/cart";
import { Updatecart } from "../../actions/cart";

const DetailProduct = () => {
  const { id } = useParams();
  const [product, setProduct] = useState(null);
  const [loading, setLoading] = useState(true);
  // const [size, setSize] = useState('large');

  useEffect(() => {
    const fetchProductById = async () => {
      try {
        const response = await fetch(`http://localhost:8089/api/v1/products/${id}`);
        const result = await response.json();

        // Kiểm tra xem API trả về dữ liệu hợp lệ hay không
        if (response.ok) {
          setProduct(result);
        } else {
          console.error("Lỗi khi lấy dữ liệu sản phẩm:", result);
        }
      } catch (error) {
        console.error("Lỗi khi kết nối đến API:", error);
      } finally {
                      setLoading(false); // Dừng trạng thái loading dù có lỗi hay không
      }
    };

    fetchProductById();
  }, [id]);

  const dispatch = useDispatch();

  const [sizeid, setSizeid] = useState(null);

  const [active, setActive] = useState(null);

  // console.log(  product?.gender);

  // product?.variations?.[0]?.sizes?.map(shoe => {

  //     console.log(shoe.value);
  //   });

  const updateSize = (e) => {
    console.log(e);
    setSizeid(e);
  };

  const cart = useSelector((state) => state.cartReducer.cartItems);

  const handleAddToCart = (id, info, price) => {
    console.log("size hiện tại đang chọn", sizeid);

    const isInCart = cart.find(
      (item) => item.id === id && item.size === sizeid
    );
    if (isInCart) {
      // Sản phẩm chưa tồn tại trong giỏ hàng

      dispatch(Updatecart(id, price)); // Cập nhật giá tiền cho sản phẩm trong giỏ hàng
    } else {
      dispatch(Addtocart(id, info, price, sizeid)); // Thêm sản phẩm vào giỏ hàng
    }
  };

  const activebox = (index) => {
    if (index === active) {
      setActive(null);
    } else {
      setActive(index);
    }
  };

  return (
    <div>


{product&&( 

<div className={styles.sectionPD}>
<Row gutter={[7, 7]}>
  <div className={styles.dsccolan}>
    <h1> Nike Dunk Low Retro</h1>
    <h2>Men's Shoe</h2>
    <h3>2,929,000₫</h3>
  </div>

  {/* imgbig - Bên phải */}
  <Col
    lg={{ span: 13, order: 2 }}
    md={{ span: 24 }}
    className={styles.sizecol}
  >
    <div className={styles.imgbig}>
      <img
        className={styles.customimage}
        src="https://static.nike.com/a/images/t_PDP_1728_v1/f_auto,q_auto:eco/9cfd9c6d-59cb-4dac-af4f-1552ddc58d36/dunk-low-retro-shoe-66RGqF.png"
        alt="Nike Dunk Low Retro Shoe"
      />
    </div>

    <h1> . </h1>
  </Col>

  {/* IMG2 - Bên trái*/}
  <Col lg={{ span: 2, order: 1 }} md={{ span: 24 }}>
    <div className={styles.IMG2}>
      <Row gutter={[7, 7]}>
        {product?.variations?.[0]?.Images?.map((anh) => (
          <Col key={anh.id} lg={{ span: 24 }} md={{ span: 4 }}>
            <div className={styles.img} key={`${anh.id}`}>
              <img src={anh.value} alt={`Image ${anh.id}`} />
            </div>
          </Col>
        ))}
      </Row>
    </div>
  </Col>

  {/* SIZE - Bên phải dưới */}
  <Col lg={{ span: 9, order: 3 }} md={{ span: 24 }}>
    <div className={styles.dsccol}>
      <h1> {product.name}</h1>
      <h2>Men's Shoe</h2>
      <h3>{product.price}$</h3>
    </div>

    <div className={styles.SIZE}>
      <div className={styles.dscSIZE}>
        <h3>Select Size</h3>
        <h3 className={styles.guide}>Size guide</h3>
      </div>

      <Row gutter={[7, 7]}>
        {product?.sizes?.map((size) => (
          <Col key={size.id} span={8}>
            <div
              className={`${styles.Sizee} ${
                active === size.id ? styles.active : ""
              } `}
              onClick={() => activebox(size.id)}
            >
              <div
                className={styles.valueSize}
                onClick={() => updateSize(size.size)}
              >
                {size.size}
              </div>
            </div>
          </Col>
        ))}
      </Row>




      <div className={styles.Button}>
        <Button
          type="primary"
          className={styles.Buttonedit}
          onClick={() =>
            handleAddToCart(product?.id, product, product?.price)
          }
        >
          Add to cart
        </Button>
      </div>

      <div className={styles.Button2}>
        <Button type="primary" className={styles.Buttonedit2}>
          Favorist ^^
        </Button>
      </div>

      <h3 className={styles.mota}>
        This product is excluded from site promotions and discounts.
      </h3>
    </div>
  </Col>
</Row>
</div>
  )}


    </div>
  );
};

export default DetailProduct;

// <Col lg={{ span: 9, order: 3 }} md={{ span: 24}}>

// </Col>
